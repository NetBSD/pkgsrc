$NetBSD: patch-libmail-mbox.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mbox.C.orig	2011-11-22 16:27:37.000000000 +0000
+++ libmail/mbox.C
@@ -32,6 +32,10 @@
 #include <signal.h>
 #include <ctype.h>
 
+#undef feof
+#undef ferror
+#undef getc
+
 using namespace std;
 
 /////////////////////////////////////////////////////////////////////////////
