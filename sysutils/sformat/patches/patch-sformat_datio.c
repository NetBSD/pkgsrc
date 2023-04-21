$NetBSD: patch-sformat_datio.c,v 1.1 2023/04/21 14:01:42 micha Exp $

Search database only in current directory and PKG_SYSCONFDIR

--- sformat/datio.c.orig	2023-01-12 14:25:40.000000000 +0000
+++ sformat/datio.c
@@ -79,12 +79,7 @@ EXPORT	int	datfileerr	__PR((char *, ...)
 
 char	*datpath[] = {
 		"",
-		"/opt/schily/etc/",
-		"/usr/bert/etc/",
-		"/etc/",
-		"/usr/etc/",
-		"/opt/csw/etc/",
-		"/opt/schily/etc/",
+		"@PKGSRC_SYSCONFDIR@/",
 		NULL
 	};
 
