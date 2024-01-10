$NetBSD: patch-lib_Mail_Qmail_Filter.pm,v 1.1 2024/01/10 16:48:23 schmonz Exp $

Honor pkgsrc-specified QMAILDIR.

--- lib/Mail/Qmail/Filter.pm.orig	2024-01-10 12:19:26.453829311 +0000
+++ lib/Mail/Qmail/Filter.pm
@@ -189,7 +189,7 @@ like the one in the L</SYNOPSIS>.
 =item 2.
 
 In the run file for your C<qmail-smtpd> instance,
-e.g. C</var/qmail/supervise/qmail-smtpd/run>,
+e.g. C<@QMAILDIR@/supervise/qmail-smtpd/run>,
 
     export QMAILQUEUE=path_to_your_frontend_script
 
