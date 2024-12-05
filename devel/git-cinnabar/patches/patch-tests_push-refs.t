$NetBSD: patch-tests_push-refs.t,v 1.1 2024/12/05 02:31:30 riastradh Exp $

Don't rely on ~/.gitconfig to set user.name:
https://github.com/glandium/git-cinnabar/issues/339

--- tests/push-refs.t.orig	2024-10-22 18:57:11.000000000 +0000
+++ tests/push-refs.t
@@ -375,7 +375,7 @@ Removing heads or branches is not suppor
 
 Pushing/deleting tags is not supported.
 
-  $ git -C repo-git -c user.email=foo@bar tag -m 'Tagged' the-tag
+  $ git -C repo-git -c user.name=foobar -c user.email=foo@bar tag -m 'Tagged' the-tag
   $ git -C repo-git push origin --tags
   To hg::.*/push-refs.t/repo-from-git (re)
    ! [remote rejected] the-tag -> the-tag (Pushing tags is unsupported)
