$NetBSD: patch-include_h.h,v 1.2 2026/11/23 10:58:38 wiz Exp $

Do not declare own errno.

--- include/h.h.orig	2026-09-12 07:11:33.000000000 +0000
+++ include/h.h
@@ -257,7 +257,7 @@ extern MODVAR int debuglevel;
 #ifdef _WIN32
 extern MODVAR int debuglevel;
 #else
-extern int debuglevel, errno, h_errno;
+extern int debuglevel, h_errno;
 #endif
 extern MODVAR int OpenFiles; /* number of files currently open */
 extern MODVAR int debuglevel, portnum, debugtty, maxusersperchannel;
