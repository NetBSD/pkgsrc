$NetBSD: patch-queue-fix.c,v 1.1 2017/04/04 07:46:14 schmonz Exp $

Configure qmail users and groups at build time.

--- queue-fix.c.orig	1999-03-14 19:54:50.000000000 +0000
+++ queue-fix.c
@@ -729,20 +729,20 @@ struct group * gr;
 	}
 
 	/*prepare the uid and gid*/
-	pw = getpwnam("qmailq");
-	if(!pw) die_user("qmailq");
+	pw = getpwnam("@QMAIL_QUEUE_USER@");
+	if(!pw) die_user("@QMAIL_QUEUE_USER@");
 	qmailq_uid = pw->pw_uid;
 
-	pw = getpwnam("qmails");
-	if(!pw) die_user("qmails");
+	pw = getpwnam("@QMAIL_SEND_USER@");
+	if(!pw) die_user("@QMAIL_SEND_USER@");
 	qmails_uid = pw->pw_uid;
 
-	pw = getpwnam("qmailr");
-	if(!pw) die_user("qmailr");
+	pw = getpwnam("@QMAIL_REMOTE_USER@");
+	if(!pw) die_user("@QMAIL_REMOTE_USER@");
 	qmailr_uid = pw->pw_uid;
 
-	gr = getgrnam("qmail");
-	if(!gr) die_group("qmail");
+	gr = getgrnam("@QMAIL_QMAIL_GROUP@");
+	if(!gr) die_group("@QMAIL_QMAIL_GROUP@");
 	qmail_gid = gr->gr_gid;
 
 	/*check that all the proper directories exist with proper credentials*/
