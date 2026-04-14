$NetBSD: patch-src_basic_macro.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Use custom macros

--- src/basic/macro.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/macro.h
@@ -70,7 +70,7 @@
 #define ALIGN4(l) (((l) + 3) & ~3)
 #define ALIGN8(l) (((l) + 7) & ~7)
 
-#ifdef __FreeBSD__
+#ifdef ALIGN
 #undef ALIGN
 #endif
 
@@ -121,6 +121,9 @@ static inline size_t ALIGN_TO(size_t l, 
         })
 
 #undef MAX
+#ifdef __MAX
+#undef __MAX
+#endif
 #define MAX(a, b) __MAX(UNIQ, (a), UNIQ, (b))
 #define __MAX(aq, a, bq, b)                             \
         ({                                              \
@@ -130,6 +133,9 @@ static inline size_t ALIGN_TO(size_t l, 
         })
 
 #undef MIN
+#ifdef __MIN
+#undef __MIN
+#endif
 #define MIN(a, b) __MIN(UNIQ, (a), UNIQ, (b))
 #define __MIN(aq, a, bq, b)                             \
         ({                                              \
