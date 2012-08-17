$NetBSD: patch-main_main.c,v 1.4 2012/08/17 15:32:31 taca Exp $

Fix fd leak on SunOS (https://bugs.php.net/bug.php?id=47675).

--- main/main.c.orig	2012-06-13 04:54:23.000000000 +0000
+++ main/main.c
@@ -2388,7 +2388,7 @@ PHPAPI int php_execute_script(zend_file_
 	zend_file_handle *prepend_file_p, *append_file_p;
 	zend_file_handle prepend_file = {0}, append_file = {0};
 #if HAVE_BROKEN_GETCWD 
-	int old_cwd_fd = -1;
+	volatile int old_cwd_fd = -1;
 #else
 	char *old_cwd;
 	ALLOCA_FLAG(use_heap)
