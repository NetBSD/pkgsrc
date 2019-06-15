$NetBSD: patch-inc_config.h,v 1.1 2019/06/15 08:41:30 adam Exp $

Add support for Interix.

--- inc/config.h.orig	2006-04-26 19:14:26.000000000 +0000
+++ inc/config.h
@@ -10,7 +10,10 @@
 #define	CONFIG_H
 
 /*efine	SIGHANDLER_T	int 		/* signal handlers are void	*/
-/*efine HAS_SYSV_SIGNAL	1		/* sigs not blocked/reset?	*/
+
+#if defined(__INTERIX)
+#define HAS_SYSV_SIGNAL	1		/* sigs not blocked/reset?	*/
+#endif
 
 #define	HAS_STDLIB_H	1		/* /usr/include/stdlib.h	*/
 #define	HAS_LIMITS_H	1		/* /usr/include/limits.h	*/
@@ -28,10 +31,17 @@
 /*efine	HAS_STRINGS_H	1		/* /usr/include/strings.h 	*/
 
 #define	HAS_UNISTD_H	1		/* /usr/include/unistd.h	*/
+
+#if defined(__INTERIX)
 #define	HAS_UTIME	1		/* POSIX utime(path, times)	*/
-/*efine	HAS_UTIMES	1		/* use utimes()	syscall instead	*/
+#else
+#define	HAS_UTIMES	1		/* use utimes()	syscall instead	*/
+#endif
 #define	HAS_UTIME_H	1		/* UTIME header file		*/
+
+#if defined(__INTERIX)
 #define	HAS_UTIMBUF	1		/* struct utimbuf		*/
+#endif
 /*efine	HAS_UTIMEUSEC   1		/* microseconds in utimbuf?	*/
 
 #endif	/* CONFIG_H */
