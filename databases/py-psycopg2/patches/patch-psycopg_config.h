$NetBSD: patch-psycopg_config.h,v 1.1 2012/03/12 11:52:28 fhajny Exp $

double defined on SunOS with GCC.
--- psycopg/config.h.orig	2011-06-08 07:42:46.000000000 +0000
+++ psycopg/config.h
@@ -141,7 +141,7 @@ static int pthread_mutex_init(pthread_mu
 #endif
 #endif
 
-#if (defined(__FreeBSD__) && __FreeBSD_version < 503000) || (defined(_WIN32) && !defined(__GNUC__)) || defined(__sun__) || defined(sun)
+#if (defined(__FreeBSD__) && __FreeBSD_version < 503000) || (defined(_WIN32) && !defined(__GNUC__)) || ((defined(__sun__) || defined(sun)) && !defined(__GNUC__))
 /* what's this, we have no round function either? */
 static double round(double num)
 {
