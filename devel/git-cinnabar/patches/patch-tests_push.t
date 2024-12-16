$NetBSD: patch-tests_push.t,v 1.1 2024/12/16 00:41:41 riastradh Exp $

Make git push fail with nonzero status when rejected upstream.
https://github.com/glandium/git-cinnabar/issues/338
https://github.com/glandium/git-cinnabar/issues/341
https://github.com/glandium/git-cinnabar/pull/342

--- tests/push.t.orig	2024-09-30 20:35:52.000000000 +0000
+++ tests/push.t
@@ -516,3 +516,94 @@ different than without the feature enabl
   * 687e015f9f646bb19797d991f2f53087297fbe14 c
   * d04f6df4abe2870ceb759263ee6aaa9241c4f93c b
   * 8b86a58578d5270969543e287634e3a2f122a338 a
+
+Create a new commit in a divergent Mercurial clone.
+
+  $ ABX=$(pwd)/abx
+  $ hg clone -q -u 636e60525868096cbdc961870493510558f41d2f abc abx
+  $ cd abx
+  $ create x
+  $ cd ..
+  $ hg -R $ABX log -G --template '{node} {branch} {desc}'
+  @  2b10b3a49ff6e308c904c2c626d7e449480b6403 default x
+  |
+  | o  bd623dea939349b06a47d5dce064255e5f1d9ec1 default c
+  |/
+  o  636e60525868096cbdc961870493510558f41d2f default b
+  |
+  o  f92470d7f6966a39dfbced6a525fe81ebf5c37b9 default a
+  
+Grab the divergent commit in git:
+
+  $ git -C abc-git -c fetch.prune=true fetch -q hg::$ABX
+  $ git -C abc-git log --graph --oneline --no-abbrev-commit FETCH_HEAD
+  * 846552c6f25c1b46e784f59d8249fb31afac2996 x
+  * bc90f2819ad12e294b313097b8763d26ca0c08ae b
+  * 8b86a58578d5270969543e287634e3a2f122a338 a
+
+Verify that pushes to the divergent hg clone are rejected by a
+reject_new_heads hook:
+XXX This should fail with nonzero exit status and not update remote refs:
+https://github.com/glandium/git-cinnabar/issues/341
+
+  $ cat <<EOF >repo/.hg/hgrc
+  > [hooks]
+  > pretxnclose.reject_new_heads = python:hgext.hooklib.reject_new_heads.hook
+  > EOF
+  $ git -C abc-git push -f origin 846552c6f25c1b46e784f59d8249fb31afac2996:branches/default/tip
+  remote: adding changesets
+  remote: adding manifests
+  remote: adding file changes
+  remote: error: pretxnclose.reject_new_heads hook failed: Changes on branch 'default' resulted in multiple heads
+  remote: transaction abort!
+  remote: rollback completed
+  \r (no-eol) (esc)
+  ERROR Changes on branch 'default' resulted in multiple heads
+  To hg::.*/push.t/repo (re)
+   ! [remote rejected] 846552c6f25c1b46e784f59d8249fb31afac2996 -> branches/default/tip (nothing changed on remote)
+  error: failed to push some refs to 'hg::.*/push.t/repo' (re)
+  [1]
+  $ rm repo/.hg/hgrc
+  $ git -C abc-git log --graph --remotes --oneline --no-abbrev-commit
+  * 687e015f9f646bb19797d991f2f53087297fbe14 c
+  * d04f6df4abe2870ceb759263ee6aaa9241c4f93c b
+  * 8b86a58578d5270969543e287634e3a2f122a338 a
+  $ hg -R $REPO log -G --template '{node} {branch} {desc}'
+  o  c70941aaa15aa6e5feae28164438f13dc3cd7b8e default c
+  |
+  o  29872b591f8d41c613bbfad38722824ab0457f17 default b
+  |
+  o  f92470d7f6966a39dfbced6a525fe81ebf5c37b9 default a
+  
+
+Verify that pushes to the divergent clone are rejected by a broken
+hook:
+
+  $ cat <<EOF >repo/.hg/hgrc
+  > [hooks]
+  > pretxnclose = python:/nonexistent:fail
+  > EOF
+  $ git -C abc-git push -f origin 846552c6f25c1b46e784f59d8249fb31afac2996:branches/default/tip
+  remote: adding changesets
+  remote: adding manifests
+  remote: adding file changes
+  remote: loading pretxnclose hook failed:
+  remote: transaction abort!
+  remote: rollback completed
+  remote: abort: No such file or directory: '/nonexistent'
+  To hg::.*/push.t/repo (re)
+   ! [remote rejected] 846552c6f25c1b46e784f59d8249fb31afac2996 -> branches/default/tip (nothing changed on remote)
+  error: failed to push some refs to 'hg::.*/push.t/repo' (re)
+  [1]
+  $ rm repo/.hg/hgrc
+  $ git -C abc-git log --graph --remotes --oneline --no-abbrev-commit
+  * 687e015f9f646bb19797d991f2f53087297fbe14 c
+  * d04f6df4abe2870ceb759263ee6aaa9241c4f93c b
+  * 8b86a58578d5270969543e287634e3a2f122a338 a
+  $ hg -R $REPO log -G --template '{node} {branch} {desc}'
+  o  c70941aaa15aa6e5feae28164438f13dc3cd7b8e default c
+  |
+  o  29872b591f8d41c613bbfad38722824ab0457f17 default b
+  |
+  o  f92470d7f6966a39dfbced6a525fe81ebf5c37b9 default a
+  
