$NetBSD: patch-libsrc_Wi_numeric.c,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Do not use non-existing function
--- libsrc/Wi/numeric.c.orig	2012-03-23 12:28:31.000000000 +0000
+++ libsrc/Wi/numeric.c
@@ -1841,7 +1841,7 @@ numeric_from_double (numeric_t n, double
 {
   char buffer[64];
 
-#if defined (bsdi) || defined (__FreeBSD__) || defined (__APPLE__)
+#if defined (bsdi) || defined (__FreeBSD__) || defined (__APPLE__) || defined(__NetBSD__)
   snprintf (buffer, sizeof (buffer), "%.16g", d);
 #else
   gcvt (d, 16, buffer);
