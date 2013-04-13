$NetBSD: patch-libsrc_Dk_Dksystem.h,v 1.1 2013/04/13 13:16:02 jaapb Exp $

errno exists in NetBSD as well
--- libsrc/Dk/Dksystem.h.orig	2012-03-23 12:28:31.000000000 +0000
+++ libsrc/Dk/Dksystem.h
@@ -141,7 +141,7 @@ void free ();
 #endif
 
 #include <errno.h>
-#if !defined(linux) && !defined(__APPLE__) && !defined (WIN32) && !defined (__CYGWIN__) && !defined(__FreeBSD__) && !defined (__cplusplus)
+#if !defined(linux) && !defined(__APPLE__) && !defined (WIN32) && !defined (__CYGWIN__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined (__cplusplus)
 extern char *sys_errlist[];
 extern int sys_nerr;
 #endif
