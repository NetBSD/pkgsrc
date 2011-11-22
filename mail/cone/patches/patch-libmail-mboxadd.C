$NetBSD: patch-libmail-mboxadd.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxadd.C.orig	2011-11-22 16:29:21.000000000 +0000
+++ libmail/mboxadd.C
@@ -16,6 +16,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#undef feof
+#undef ferror
+#undef getc
+
 using namespace std;
 
 mail::mbox::folder::add::add(mail::mbox &mboxArg, string pathArg,
