$NetBSD: patch-libmail-mboxgetmessage.C,v 1.1 2011/11/22 18:12:35 joerg Exp $

Use stdio functions to ensure that the mail::file cast to FILE * happens.

--- libmail/mboxgetmessage.C.orig	2011-11-22 16:30:48.000000000 +0000
+++ libmail/mboxgetmessage.C
@@ -16,6 +16,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#undef feof
+
 using namespace std;
 
 mail::mbox::GenericGetMessageTask::GenericGetMessageTask(mail::mbox &mboxAccount,
