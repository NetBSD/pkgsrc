$NetBSD: patch-tar_tar.c,v 1.1 2024/05/23 21:48:53 cheusov Exp $

--- tar/tar.c.orig	2007-04-14 13:48:55.000000000 +0000
+++ tar/tar.c
@@ -94,13 +94,13 @@ static const char sccsid[] USED = "@(#)t
 #include <sys/st01.h>
 #endif	/* SVR4.2MP */
 
-#ifdef	_AIX
+#if defined(_AIX) || defined(__linux__)
 #include <sys/sysmacros.h>
 #endif
 
-#ifndef	major
+#ifdef __sun
 #include <sys/mkdev.h>
-#endif	/* !major */
+#endif	/* __sun */
 
 #include <getdir.h>
 #include <asciitype.h>
