$NetBSD: patch-src_mesa_main_macros.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

ALIGN is also defined in sys/param.h on NetBSD.

Extend undefining ALIGN to all other OSes.

--- src/mesa/main/macros.h.orig	2017-11-10 23:18:56.000000000 +0000
+++ src/mesa/main/macros.h
@@ -677,6 +677,9 @@ minify(unsigned value, unsigned levels)
  *
  * \sa ROUND_DOWN_TO()
  */
+#ifdef ALIGN
+#undef ALIGN
+#endif
 static inline uintptr_t
 ALIGN(uintptr_t value, int32_t alignment)
 {
