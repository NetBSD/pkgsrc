$NetBSD: patch-libmail-mboxread.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxread.C.orig	2011-11-22 16:32:57.000000000 +0000
+++ libmail/mboxread.C
@@ -12,6 +12,8 @@
 #include <ctype.h>
 #include <errno.h>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::GenericReadTask::GenericReadTask(mail::mbox &mboxAccount,
