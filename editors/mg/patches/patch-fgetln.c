$NetBSD: patch-fgetln.c,v 1.1 2014/07/07 18:06:58 jperkin Exp $

SunOS needs fgetln support.

--- fgetln.c.orig	2008-12-30 12:41:23.000000000 +0000
+++ fgetln.c
@@ -27,7 +27,7 @@
 #include <stdio.h>
 #include <string.h>
 
-#if defined (__GLIBC__) || defined (__CYGWIN__)  /* FreeWRT: only build
+#if defined (__GLIBC__) || defined (__CYGWIN__) || defined(__sun) /* FreeWRT: only build
 						      this where needed */
 char *fgetln(FILE *, size_t *);
 
