$NetBSD: patch-src_ft2__header.h,v 1.1 2019/07/22 23:38:47 fox Exp $

Add the HAS_SSE macro so that build failures do not occur in i386
systems that lack SSE support.

Suggestion by leot@

--- src/ft2_header.h.orig	2019-07-22 16:21:07.522137321 +0000
+++ src/ft2_header.h
@@ -77,7 +77,7 @@
 #define float2int32_round(i, f) (i = _mm_cvt_ss2si(_mm_load_ss(&f)))
 #define double2int32_round(i, d) (i = _mm_cvtsd_si32(_mm_load_sd(&d)))
 
-#elif defined _WIN32 || defined __i386__ // may have SSE and SSE2
+#elif defined HAS_SSE && (defined _WIN32 || defined __i386__) // may have SSE and SSE2
 
 #define float2int32_round(i, f) \
 	if (cpu.hasSSE) \
