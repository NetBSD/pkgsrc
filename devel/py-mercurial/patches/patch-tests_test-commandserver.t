$NetBSD: patch-tests_test-commandserver.t,v 1.1 2016/03/02 19:31:13 wiz Exp $

changeset:   34663:332926212ef8
user:        FUJIWARA Katsunori <foozy@lares.dti.ne.jp>
date:        Wed Feb 24 06:10:46 2016 +0900
files:       mercurial/repoview.py tests/test-commandserver.t
description:
repoview: discard filtered changelog if index isn't shared with unfiltered

--- tests/test-commandserver.t.orig	2016-03-02 00:03:43.000000000 +0000
+++ tests/test-commandserver.t
@@ -725,3 +725,133 @@ unix domain socket:
   [255]
 
 #endif
+
+  $ cd ..
+
+Test that accessing to invalid changelog cache is avoided at
+subsequent operations even if repo object is reused even after failure
+of transaction (see 0a7610758c42 also)
+
+"hg log" after failure of transaction is needed to detect invalid
+cache in repoview: this can't detect by "hg verify" only.
+
+Combination of "finalization" and "empty-ness of changelog" (2 x 2 =
+4) are tested, because '00changelog.i' are differently changed in each
+cases.
+
+  $ cat > $TESTTMP/failafterfinalize.py <<EOF
+  > # extension to abort transaction after finalization forcibly
+  > from mercurial import commands, error, extensions, lock as lockmod
+  > def fail(tr):
+  >     raise error.Abort('fail after finalization')
+  > def reposetup(ui, repo):
+  >     class failrepo(repo.__class__):
+  >         def commitctx(self, ctx, error=False):
+  >             if self.ui.configbool('failafterfinalize', 'fail'):
+  >                 # 'sorted()' by ASCII code on category names causes
+  >                 # invoking 'fail' after finalization of changelog
+  >                 # using "'cl-%i' % id(self)" as category name
+  >                 self.currenttransaction().addfinalize('zzzzzzzz', fail)
+  >             return super(failrepo, self).commitctx(ctx, error)
+  >     repo.__class__ = failrepo
+  > EOF
+
+  $ hg init repo3
+  $ cd repo3
+
+  $ cat <<EOF >> $HGRCPATH
+  > [ui]
+  > logtemplate = {rev} {desc|firstline} ({files})\n
+  > 
+  > [extensions]
+  > failafterfinalize = $TESTTMP/failafterfinalize.py
+  > EOF
+
+- test failure with "empty changelog"
+
+  $ echo foo > foo
+  $ hg add foo
+
+(failuer before finalization)
+
+  >>> from hgclient import readchannel, runcommand, check
+  >>> @check
+  ... def abort(server):
+  ...     readchannel(server)
+  ...     runcommand(server, ['commit',
+  ...                         '--config', 'hooks.pretxncommit=false',
+  ...                         '-mfoo'])
+  ...     runcommand(server, ['log'])
+  ...     runcommand(server, ['verify', '-q'])
+  *** runcommand commit --config hooks.pretxncommit=false -mfoo
+  transaction abort!
+  rollback completed
+  abort: pretxncommit hook exited with status 1
+   [255]
+  *** runcommand log
+  *** runcommand verify -q
+
+(failuer after finalization)
+
+  >>> from hgclient import readchannel, runcommand, check
+  >>> @check
+  ... def abort(server):
+  ...     readchannel(server)
+  ...     runcommand(server, ['commit',
+  ...                         '--config', 'failafterfinalize.fail=true',
+  ...                         '-mfoo'])
+  ...     runcommand(server, ['log'])
+  ...     runcommand(server, ['verify', '-q'])
+  *** runcommand commit --config failafterfinalize.fail=true -mfoo
+  transaction abort!
+  rollback completed
+  abort: fail after finalization
+   [255]
+  *** runcommand log
+  *** runcommand verify -q
+
+- test failure with "not-empty changelog"
+
+  $ echo bar > bar
+  $ hg add bar
+  $ hg commit -mbar bar
+
+(failure before finalization)
+
+  >>> from hgclient import readchannel, runcommand, check
+  >>> @check
+  ... def abort(server):
+  ...     readchannel(server)
+  ...     runcommand(server, ['commit',
+  ...                         '--config', 'hooks.pretxncommit=false',
+  ...                         '-mfoo', 'foo'])
+  ...     runcommand(server, ['log'])
+  ...     runcommand(server, ['verify', '-q'])
+  *** runcommand commit --config hooks.pretxncommit=false -mfoo foo
+  transaction abort!
+  rollback completed
+  abort: pretxncommit hook exited with status 1
+   [255]
+  *** runcommand log
+  0 bar (bar)
+  *** runcommand verify -q
+
+(failure after finalization)
+
+  >>> from hgclient import readchannel, runcommand, check
+  >>> @check
+  ... def abort(server):
+  ...     readchannel(server)
+  ...     runcommand(server, ['commit',
+  ...                         '--config', 'failafterfinalize.fail=true',
+  ...                         '-mfoo', 'foo'])
+  ...     runcommand(server, ['log'])
+  ...     runcommand(server, ['verify', '-q'])
+  *** runcommand commit --config failafterfinalize.fail=true -mfoo foo
+  transaction abort!
+  rollback completed
+  abort: fail after finalization
+   [255]
+  *** runcommand log
+  0 bar (bar)
+  *** runcommand verify -q
