$NetBSD: patch-libmail-mboxgetmessage.C,v 1.2 2012/06/09 11:51:36 adam Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxgetmessage.C.orig	2011-11-22 16:30:48.000000000 +0000
+++ libmail/mboxgetmessage.C
@@ -15,6 +15,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::GenericGetMessageTask::GenericGetMessageTask(mail::mbox &mboxAccount,
