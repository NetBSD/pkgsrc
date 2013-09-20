$NetBSD: patch-system.h,v 1.2 2013/09/20 17:26:14 ryoon Exp $

* Detect setprogname(3) in configure script.

--- system.h.orig	2013-01-30 15:33:12.000000000 +0000
+++ system.h
@@ -112,7 +112,7 @@ typedef	char * security_context_t;
 #define _free(_ptr) rfree((_ptr))
 
 /* Retrofit glibc __progname */
-#if defined __GLIBC__ && __GLIBC__ >= 2
+#if (defined __GLIBC__ && __GLIBC__ >= 2) || defined(HAVE_SETPROGNAME)
 #if __GLIBC_MINOR__ >= 1
 #define	__progname	__assert_program_name
 #endif
