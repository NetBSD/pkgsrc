$NetBSD: patch-main_main.c,v 1.3 2013/01/17 15:48:09 taca Exp $

Fix fd leak on SunOS (https://bugs.php.net/bug.php?id=47675).

--- main/main.c.orig	2013-01-16 07:10:30.000000000 +0000
+++ main/main.c
@@ -2407,7 +2407,7 @@ PHPAPI int php_execute_script(zend_file_
 	zend_file_handle *prepend_file_p, *append_file_p;
 	zend_file_handle prepend_file = {0}, append_file = {0};
 #if HAVE_BROKEN_GETCWD
-	int old_cwd_fd = -1;
+	volatile int old_cwd_fd = -1;
 #else
 	char *old_cwd;
 	ALLOCA_FLAG(use_heap)
