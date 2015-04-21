$NetBSD: patch-src_osd_sdl_osinline.h,v 1.1 2015/04/21 17:20:39 joerg Exp $

--- src/osd/sdl/osinline.h.orig	2015-04-17 15:09:28.000000000 +0000
+++ src/osd/sdl/osinline.h
@@ -83,6 +83,29 @@ _osd_exchange64(INT64 volatile *ptr, INT
 
 #endif /* __ppc64__ || __PPC64__ */
 
+#elif defined(__arm__)
+INLINE void ATTR_FORCE_INLINE
+osd_yield_processor(void)
+{
+}
+
+INLINE INT32 ATTR_UNUSED ATTR_NONNULL(1) ATTR_FORCE_INLINE
+_osd_exchange32(INT32 volatile *ptr, INT32 exchange)
+{
+	INT32 before;
+	do {
+		before = *ptr;
+	} while (!__sync_bool_compare_and_swap(ptr, before, exchange));
+	return before;
+}
+
+INLINE int ATTR_UNUSED ATTR_NONNULL(1) ATTR_FORCE_INLINE
+_osd_compare_exchange32(INT32 volatile *ptr, INT32 before, INT32 after)
+{
+	return __sync_bool_compare_and_swap(ptr, before, after);
+}
+#define osd_exchange32 _osd_exchange32
+#define osd_compare_exchange32 _osd_compare_exchange32
 #else
 
 #error "no matching assembler implementations found - please compile with NOASM=1"
