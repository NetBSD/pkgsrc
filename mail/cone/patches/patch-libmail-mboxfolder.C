$NetBSD: patch-libmail-mboxfolder.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxfolder.C.orig	2011-11-22 16:30:20.000000000 +0000
+++ libmail/mboxfolder.C
@@ -39,6 +39,8 @@
 
 #include <vector>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::folder::folder(string pathArg,
