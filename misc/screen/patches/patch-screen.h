$NetBSD: patch-screen.h,v 1.1 2025/05/12 16:03:20 wiz Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- screen.h.orig	2024-08-28 19:55:03.000000000 +0000
+++ screen.h
@@ -291,8 +291,6 @@ extern int nversion;
 extern uid_t own_uid;
 extern int queryflag;
 extern int rflag;
-extern int tty_mode;
-extern int tty_oldmode;
 extern pid_t MasterPid;
 extern int MsgMinWait;
 extern int MsgWait;
