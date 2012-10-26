$NetBSD: patch-tests_document-saver.c,v 1.1 2012/10/26 15:51:13 jperkin Exp $

Define ACCESSPERMS for systems which do not have it.

--- tests/document-saver.c.orig	2012-10-26 15:41:49.737048981 +0000
+++ tests/document-saver.c	2012-10-26 15:42:28.479034452 +0000
@@ -27,6 +27,10 @@
 #include <string.h>
 #include <sys/stat.h>
 
+#ifndef ACCESSPERMS
+#define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)
+#endif
+
 #define DEFAULT_LOCAL_URI "/tmp/gedit-document-saver-test.txt"
 #define DEFAULT_REMOTE_URI "sftp://localhost/tmp/gedit-document-saver-test.txt"
 #define DEFAULT_CONTENT "hello world!"
