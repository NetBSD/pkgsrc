$NetBSD: patch-src_rastertokmlf.c,v 1.1 2017/07/01 22:13:26 joerg Exp $

Fix build with CUPS 2.0.

--- src/rastertokmlf.c.orig	2017-07-01 21:05:32.072615512 +0000
+++ src/rastertokmlf.c
@@ -53,6 +53,7 @@
  */
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 //#include <cups/string.h>
 #include <cups/language.h>
 #include <cups/raster.h>
