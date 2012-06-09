$NetBSD: patch-libmail-tmpaccount.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/tmpaccount.C.orig	2011-04-04 11:58:20.000000000 +0000
+++ libmail/tmpaccount.C
@@ -12,6 +12,8 @@
 #include <sys/stat.h>
 #include <cstring>
 
+#undef ferror
+
 using namespace std;
 
 LIBMAIL_START
