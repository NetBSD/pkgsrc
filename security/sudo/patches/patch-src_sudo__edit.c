$NetBSD: patch-src_sudo__edit.c,v 1.1 2016/09/16 11:50:38 jperkin Exp $

Don't assume O_SEARCH implies support for O_DIRECTORY.

--- src/sudo_edit.c.orig	2016-06-18 02:44:21.000000000 +0000
+++ src/sudo_edit.c
@@ -347,7 +347,11 @@ dir_is_writable(int dfd, struct user_det
  * Use O_SEARCH/O_PATH and/or O_DIRECTORY where possible.
  */
 #if defined(O_SEARCH)
+# if defined(O_DIRECTORY)
 # define DIR_OPEN_FLAGS	(O_SEARCH|O_DIRECTORY)
+# else
+# define DIR_OPEN_FLAGS	(O_SEARCH)
+# endif
 #elif defined(O_PATH)
 # define DIR_OPEN_FLAGS	(O_PATH|O_DIRECTORY)
 #elif defined(O_DIRECTORY)
