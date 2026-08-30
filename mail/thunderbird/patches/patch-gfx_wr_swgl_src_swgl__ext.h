$NetBSD: patch-gfx_wr_swgl_src_swgl__ext.h,v 1.1 2026/08/30 10:26:05 ryoon Exp $

--- gfx/wr/swgl/src/swgl_ext.h.orig	2026-08-12 13:09:04.000000000 +0000
+++ gfx/wr/swgl/src/swgl_ext.h
@@ -8,6 +8,8 @@
 // efficiently process it and modulate it with color without incurring blend
 // stage overheads.
 #include <cstdint>
+#include <cmath>
+using std::isfinite;
 
 template <typename P, typename C>
 static void commit_masked_solid_span(P* buf, C color, int len) {
