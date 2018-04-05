$NetBSD: patch-psycopg_solaris__support.c,v 1.1 2018/04/05 09:45:13 jperkin Exp $

Only supply timeradd/timersub if they are missing.

--- psycopg/solaris_support.c.orig	2018-02-06 02:48:43.000000000 +0000
+++ psycopg/solaris_support.c
@@ -27,7 +27,7 @@
 #include "psycopg/psycopg.h"
 #include "psycopg/solaris_support.h"
 
-#if defined(__sun) && defined(__SVR4)
+#if defined(__sun) && defined(__SVR4) && !defined(timeradd)
 /* timeradd is missing on Solaris */
 void
 timeradd(struct timeval *a, struct timeval *b, struct timeval *c)
