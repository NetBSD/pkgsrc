$NetBSD: patch-include_h.h,v 1.1 2022/03/04 08:44:33 nia Exp $

Do not declare own errno.

--- include/h.h.orig	2020-01-22 06:30:42.000000000 +0000
+++ include/h.h
@@ -209,7 +209,7 @@ extern int dgets(int, char *, int);
 #ifdef _WIN32
 extern MODVAR int debuglevel;
 #else
-extern int debuglevel, errno, h_errno;
+extern int debuglevel, h_errno;
 #endif
 extern MODVAR int OpenFiles;  /* number of files currently open */
 extern MODVAR int debuglevel, portnum, debugtty, maxusersperchannel;
