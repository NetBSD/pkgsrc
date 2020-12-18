$NetBSD: patch-include_xine_xineutils.h,v 1.2 2020/12/18 23:33:06 nia Exp $

Don't reimplement memcpy. Actually not compatible with clang:

../../include/xine/xineutils.h:211:63: error: fields must have a constant size:
'variable length array in structure' extension will never be supported

--- include/xine/xineutils.h.orig	2020-11-19 10:30:37.000000000 +0000
+++ include/xine/xineutils.h
@@ -200,35 +200,6 @@ extern void *(* xine_fast_memcpy)(void *
 /* len (usually) < 500, but not a build time constant. */
 #define xine_small_memcpy(xsm_to,xsm_from,xsm_len) memcpy (xsm_to, xsm_from, xsm_len)
 
-#if (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__clang__)
-#  if defined(ARCH_X86)
-#    undef xine_small_memcpy
-static inline void *xine_small_memcpy (void *to, const void *from, size_t len) {
-  void *t2 = to;
-  size_t l2 = len;
-#    if !defined(__clang__)
-  __asm__ __volatile__ (
-    "cld\n\trep movsb"
-    : "=S" (from), "=D" (t2), "=c" (l2), "=m" (*(struct {char foo[len];} *)to)
-    : "0"  (from), "1"  (t2), "2"  (l2)
-    : "cc"
-  );
-#    else /* clang dislikes virtual variable size struct */
-  __asm__ __volatile__ (
-      "cld\n\trep movsb"
-      : "=S" (from), "=D" (t2), "=c" (l2)
-      : "0"  (from), "1"  (t2), "2"  (l2)
-      : "cc", "memory"
-  );
-#    endif
-  (void)from;
-  (void)t2;
-  (void)l2;
-  return to;
-}
-#  endif
-#endif
-
 /*
  * Debug stuff
  */
