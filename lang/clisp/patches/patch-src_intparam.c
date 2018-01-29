$NetBSD: patch-src_intparam.c,v 1.1 2018/01/29 17:38:23 jperkin Exp $

Fix SunOS/C99.

--- src/intparam.c.orig	2008-12-22 14:12:12.000000000 +0000
+++ src/intparam.c
@@ -8,7 +8,9 @@
  * zu verhindern, bei AIX 3.2.5 (rs6000-ibm-aix3.2.5) jedoch nicht. Wir
  * müssen Gewalt anwenden.
  */
+#if !defined(__sun) || (__STDC_VERSION__-0 < 199901L)
 #define _POSIX_SOURCE
+#endif
 #define uchar  os_uchar
 #define ushort os_ushort
 #define uint   os_uint
