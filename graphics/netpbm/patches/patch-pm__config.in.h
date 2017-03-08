$NetBSD: patch-pm__config.in.h,v 1.4 2017/03/08 14:48:30 jperkin Exp $

Remove bogus SYSV section.

--- pm_config.in.h.orig	2017-02-04 18:09:33.000000000 +0000
+++ pm_config.in.h
@@ -74,7 +74,7 @@
 ** for the format of the color database file.
 */
 
-#if (defined(SYSV) || defined(__amigaos__))
+#if (defined(__amigaos__))
 
 #include <string.h>
 
