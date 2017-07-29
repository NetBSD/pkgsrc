$NetBSD: patch-terps_nitfol_nitfol.h,v 1.1 2017/07/29 06:25:39 wiz Exp $

No point in using inline, and it breaks compilation with gcc-5.4
on NetBSD-8.99.1/amd64.

--- terps/nitfol/nitfol.h.orig	2011-10-19 20:34:39.000000000 +0000
+++ terps/nitfol/nitfol.h
@@ -115,15 +115,7 @@ typedef unsigned long offset;
 #define XPASTE(a, b) PASTE(a, b)
 
 
-#if defined(__cplusplus) || defined(USE_INLINE)
-#define N_INLINE inline
-#elif defined(INLINE)
-#define N_INLINE INLINE
-#elif defined(__GNUC__)
-#define N_INLINE __inline__
-#else
 #define N_INLINE
-#endif
 
 
 
