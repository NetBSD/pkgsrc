$NetBSD: patch-psycopg_solaris__support.h,v 1.1 2018/04/05 09:45:13 jperkin Exp $

Only supply timeradd/timersub if they are missing.

--- psycopg/solaris_support.h.orig	2018-02-06 02:48:43.000000000 +0000
+++ psycopg/solaris_support.h
@@ -29,9 +29,10 @@
 
 #if defined(__sun) && defined(__SVR4)
 #include <sys/time.h>
-
+#ifndef timeradd
 extern HIDDEN void timeradd(struct timeval *a, struct timeval *b, struct timeval *c);
 extern HIDDEN void timersub(struct timeval *a, struct timeval *b, struct timeval *c);
 #endif
+#endif
 
 #endif /* !defined(PSYCOPG_SOLARIS_SUPPORT_H) */
