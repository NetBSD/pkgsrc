$NetBSD: patch-src_mesa_main_macros.h,v 1.1 2016/01/05 13:02:57 tnn Exp $

ALIGN is also defined in sys/param.h on NetBSD.

--- src/mesa/main/macros.h.orig	2015-12-09 16:10:13.000000000 +0000
+++ src/mesa/main/macros.h
@@ -690,6 +690,9 @@ minify(unsigned value, unsigned levels)
  *
  * \sa ROUND_DOWN_TO()
  */
+#if defined(__NetBSD__)
+#undef ALIGN
+#endif
 static inline uintptr_t
 ALIGN(uintptr_t value, int32_t alignment)
 {
