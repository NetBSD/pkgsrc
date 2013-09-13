$NetBSD: patch-system.h,v 1.1 2013/09/13 12:41:32 ryoon Exp $

* NetBSD has setprogname(3).

--- system.h.orig	2013-01-30 15:33:12.000000000 +0000
+++ system.h
@@ -112,7 +112,7 @@ typedef	char * security_context_t;
 #define _free(_ptr) rfree((_ptr))
 
 /* Retrofit glibc __progname */
-#if defined __GLIBC__ && __GLIBC__ >= 2
+#if (defined __GLIBC__ && __GLIBC__ >= 2) || defined(__NetBSD__)
 #if __GLIBC_MINOR__ >= 1
 #define	__progname	__assert_program_name
 #endif
