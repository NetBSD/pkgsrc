$NetBSD: patch-libmail-tmpaccount.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/tmpaccount.C.orig	2011-11-22 16:37:21.000000000 +0000
+++ libmail/tmpaccount.C
@@ -14,6 +14,8 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#undef ferror
+
 using namespace std;
 
 LIBMAIL_START
