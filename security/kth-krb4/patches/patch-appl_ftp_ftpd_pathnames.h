$NetBSD: patch-appl_ftp_ftpd_pathnames.h,v 1.1 2011/11/28 19:33:13 marino Exp $

--- appl/ftp/ftpd/pathnames.h.orig	2002-08-12 15:09:14.000000000 +0000
+++ appl/ftp/ftpd/pathnames.h
@@ -49,7 +49,9 @@
 #define _PATH_BSHELL "/bin/sh"
 #endif
 
+#ifndef _PATH_FTPUSERS
 #define	_PATH_FTPUSERS		SYSCONFDIR "/ftpusers"
+#endif
 #define	_PATH_FTPCHROOT		SYSCONFDIR "/ftpchroot"
 #define	_PATH_FTPWELCOME	SYSCONFDIR "/ftpwelcome"
 #define	_PATH_FTPLOGINMESG	SYSCONFDIR "/motd"
