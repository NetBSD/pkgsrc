$NetBSD: patch-libmail-mbox.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mbox.C.orig	2011-11-22 16:27:37.000000000 +0000
+++ libmail/mbox.C
@@ -31,6 +31,10 @@
 #include <signal.h>
 #include <ctype.h>
 
+#undef feof
+#undef ferror
+#undef getc
+
 using namespace std;
 
 /////////////////////////////////////////////////////////////////////////////
