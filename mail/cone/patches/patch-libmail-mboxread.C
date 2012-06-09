$NetBSD: patch-libmail-mboxread.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxread.C.orig	2011-11-22 16:32:57.000000000 +0000
+++ libmail/mboxread.C
@@ -11,6 +11,8 @@
 #include <ctype.h>
 #include <errno.h>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::GenericReadTask::GenericReadTask(mail::mbox &mboxAccount,
