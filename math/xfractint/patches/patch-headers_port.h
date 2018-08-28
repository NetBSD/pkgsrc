$NetBSD: patch-headers_port.h,v 1.1 2018/08/28 11:54:54 schmonz Exp $

--- headers/port.h.orig	2015-07-04 13:09:32.000000000 +0000
+++ headers/port.h
@@ -44,7 +44,7 @@
 /* If endian.h is not present, it can be handled in the code below, */
 /* but if you have this file, it can make it more fool proof. */
 #if (defined(XFRACT) && !defined(__sun))
-#if defined(sgi)
+#if defined(sgi) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
@@ -353,6 +353,10 @@ extern struct DIR_SEARCH DTA;   /* Disk 
 #define DO_NOT_USE_LONG_DOUBLE
 #endif
 
+#if defined(__NetBSD__) || defined(__DragonFly__)
+#define DO_NOT_USE_LONG_DOUBLE
+#endif
+
 #ifndef DO_NOT_USE_LONG_DOUBLE
 #ifdef LDBL_DIG
 /* this is what we're hoping for */
