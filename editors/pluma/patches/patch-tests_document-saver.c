$NetBSD: patch-tests_document-saver.c,v 1.1 2016/05/21 19:21:10 youri Exp $

Provide compat ACCESSPERMS define.

--- tests/document-saver.c.orig	2015-10-10 00:14:30.000000000 +0000
+++ tests/document-saver.c
@@ -29,6 +29,10 @@
 #include <string.h>
 #include <sys/stat.h>
 
+#ifndef ACCESSPERMS
+#define ACCESSPERMS	(S_IRWXU|S_IRWXG|S_IRWXO)
+#endif
+
 #define DEFAULT_LOCAL_URI "/tmp/pluma-document-saver-test.txt"
 #define DEFAULT_REMOTE_URI "sftp://localhost/tmp/pluma-document-saver-test.txt"
 #define DEFAULT_CONTENT "hello world!"
