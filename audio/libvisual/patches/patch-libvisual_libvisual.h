$NetBSD: patch-libvisual_libvisual.h,v 1.1 2026/01/02 12:29:21 adam Exp $

For integer types.

--- libvisual/libvisual.h.orig	2026-01-02 11:17:46.741380162 +0000
+++ libvisual/libvisual.h
@@ -24,6 +24,7 @@
 #ifndef LV_LIBVISUAL_H
 #define LV_LIBVISUAL_H
 
+#include <stdint.h>
 #include <libvisual/lvconfig.h>
 
 #include <libvisual/lv_bits.h>
