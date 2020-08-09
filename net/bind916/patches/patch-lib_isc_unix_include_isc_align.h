$NetBSD: patch-lib_isc_unix_include_isc_align.h,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/unix/include/isc/align.h.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/unix/include/isc/align.h
@@ -16,3 +16,8 @@
 #else /* ifdef HAVE_STDALIGN_H */
 #define alignas(x) __attribute__((__aligned__(x)))
 #endif /* ifdef HAVE_STDALIGN_H */
+#ifdef __lint__
+// XXX: bug
+#undef alignas
+#define alignas(a)
+#endif
