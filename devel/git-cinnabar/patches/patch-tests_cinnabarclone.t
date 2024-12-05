$NetBSD: patch-tests_cinnabarclone.t,v 1.1 2024/12/05 02:31:30 riastradh Exp $

Work around NetBSD differences in test output.
https://github.com/glandium/git-cinnabar/issues/340

--- tests/cinnabarclone.t.orig	2023-10-07 12:16:45.000000000 +0000
+++ tests/cinnabarclone.t
@@ -110,7 +110,7 @@ TODO: Ideally, the error message would s
   Cloning into 'repo-git'...
   Fetching cinnabar metadata from http://localhost:8080/
   \r (no-eol) (esc)
-  ERROR unable to access 'http://localhost:8080/': Failed to connect to localhost port 8080.* (re)
+  ERROR unable to access 'http://localhost:8080/': .* (re)
   \r (no-eol) (esc)
   WARNING Falling back to normal clone.
 
