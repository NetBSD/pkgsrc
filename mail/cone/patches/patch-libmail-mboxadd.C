$NetBSD: patch-libmail-mboxadd.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxadd.C.orig	2011-11-22 16:29:21.000000000 +0000
+++ libmail/mboxadd.C
@@ -15,6 +15,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#undef feof
+#undef ferror
+#undef getc
+
 using namespace std;
 
 mail::mbox::folder::add::add(mail::mbox &mboxArg, string pathArg,
