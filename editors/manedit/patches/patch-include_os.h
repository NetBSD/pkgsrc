$NetBSD: patch-include_os.h,v 1.1 2011/12/08 06:49:42 marino Exp $

--- ../include/os.h.orig	2007-02-11 08:00:00.000000000 +0000
+++ ../include/os.h
@@ -16,7 +16,7 @@
 
 #include <limits.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 # include <paths.h>
 #endif
 
@@ -52,7 +52,7 @@
 # define _PATH_DEVNULL		"/dev/null"
 #endif
 
-#if !defined(_AIX) && !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(_AIX) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 # ifndef _PATH_MAILDIR
 #  define _PATH_MAILDIR		"/var/spool/mail"
 # endif
@@ -245,7 +245,7 @@
 /* Bit types still not defined? */
 #if !defined(__BIT_TYPES_DEFINED__) && !defined(WIN32) && !defined(__hpux)
 //#define __BIT_TYPES_DEFINED__ Dan S: Multiple declaration problem.
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 
 // typedef char			int8_t;  Dan S: multiple declaration problem.
 typedef unsigned char           u_int8_t;
@@ -266,7 +266,7 @@ typedef unsigned long long      u_int64_
 
 # endif	/* __GNUC__ >= 2 */
 
-#endif	/* __FreeBSD__ */
+#endif	/* __FreeBSD__ __DragonFly__*/
 #endif	/* __BIT_TYPES_DEFINED__ */
 
 
