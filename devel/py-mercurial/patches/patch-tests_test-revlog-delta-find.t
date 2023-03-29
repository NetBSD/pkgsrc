$NetBSD: patch-tests_test-revlog-delta-find.t,v 1.1 2023/03/29 11:29:27 wiz Exp $

cp(1) doesn't like -ar
https://bz.mercurial-scm.org/show_bug.cgi?id=6808

--- tests/test-revlog-delta-find.t.orig	2023-03-23 23:11:29.000000000 +0000
+++ tests/test-revlog-delta-find.t
@@ -198,7 +198,7 @@ Check the path.*:pulled-delta-reuse-poli
 
 Get a repository with the bad parent picked and a clone ready to pull the merge
 
-  $ cp -ar bundle-reuse-enabled peer-bad-delta
+  $ cp -aR bundle-reuse-enabled peer-bad-delta
   $ hg clone peer-bad-delta local-pre-pull --rev `cat large.node` --rev `cat small.node` --quiet
   DBG-DELTAS: CHANGELOG: * (glob)
   DBG-DELTAS: CHANGELOG: * (glob)
@@ -222,7 +222,7 @@ Pull with no value (so the default)
 
 default is to reuse the (bad) delta
 
-  $ cp -ar local-pre-pull local-no-value
+  $ cp -aR local-pre-pull local-no-value
   $ hg -R local-no-value pull --quiet
   DBG-DELTAS: CHANGELOG: * (glob)
   DBG-DELTAS: MANIFESTLOG: * (glob)
@@ -233,7 +233,7 @@ Pull with explicitly the default
 
 default is to reuse the (bad) delta
 
-  $ cp -ar local-pre-pull local-default
+  $ cp -aR local-pre-pull local-default
   $ hg -R local-default pull --quiet --config 'paths.default:pulled-delta-reuse-policy=default'
   DBG-DELTAS: CHANGELOG: * (glob)
   DBG-DELTAS: MANIFESTLOG: * (glob)
@@ -244,7 +244,7 @@ Pull with no-reuse
 
 We don't reuse the base, so we get a better delta
 
-  $ cp -ar local-pre-pull local-no-reuse
+  $ cp -aR local-pre-pull local-no-reuse
   $ hg -R local-no-reuse pull --quiet --config 'paths.default:pulled-delta-reuse-policy=no-reuse'
   DBG-DELTAS: CHANGELOG: * (glob)
   DBG-DELTAS: MANIFESTLOG: * (glob)
@@ -255,7 +255,7 @@ Pull with try-base
 
 We requested to use the (bad) delta
 
-  $ cp -ar local-pre-pull local-try-base
+  $ cp -aR local-pre-pull local-try-base
   $ hg -R local-try-base pull --quiet --config 'paths.default:pulled-delta-reuse-policy=try-base'
   DBG-DELTAS: CHANGELOG: * (glob)
   DBG-DELTAS: MANIFESTLOG: * (glob)
@@ -266,8 +266,8 @@ Case where we force a "bad" delta to be 
 
 We build a very different file content to force a full snapshot
 
-  $ cp -ar peer-bad-delta peer-bad-delta-with-full
-  $ cp -ar local-pre-pull local-pre-pull-full
+  $ cp -aR peer-bad-delta peer-bad-delta-with-full
+  $ cp -aR local-pre-pull local-pre-pull-full
   $ echo '[paths]' >> local-pre-pull-full/.hg/hgrc
   $ echo 'default=../peer-bad-delta-with-full' >> local-pre-pull-full/.hg/hgrc
 
@@ -286,7 +286,7 @@ The bundling process creates a delta aga
 is an invalid chain for the client, so it is not considered and we do a full
 snapshot again.
 
-  $ cp -ar local-pre-pull-full local-try-base-full
+  $ cp -aR local-pre-pull-full local-try-base-full
   $ hg -R local-try-base-full pull --quiet \
   > --config 'paths.default:pulled-delta-reuse-policy=try-base'
   DBG-DELTAS: CHANGELOG: * (glob)
@@ -301,7 +301,7 @@ Check that "forced" behavior do not chal
 
 A full bundle should be accepted as full bundle without recomputation
 
-  $ cp -ar local-pre-pull-full local-forced-full
+  $ cp -aR local-pre-pull-full local-forced-full
   $ hg -R local-forced-full pull --quiet \
   > --config 'paths.default:pulled-delta-reuse-policy=forced'
   DBG-DELTAS: CHANGELOG: * (glob)
@@ -322,7 +322,7 @@ more subtle to test this behavior.
 
   $ hg bundle -R peer-bad-delta-with-full --all --config devel.bundle.delta=p1 all-p1.hg
   5 changesets found
-  $ cp -ar local-pre-pull-full local-forced-full-p1
+  $ cp -aR local-pre-pull-full local-forced-full-p1
   $ hg -R local-forced-full-p1 pull --quiet \
   > --config 'paths.*:pulled-delta-reuse-policy=forced' all-p1.hg
   DBG-DELTAS: CHANGELOG: * (glob)
