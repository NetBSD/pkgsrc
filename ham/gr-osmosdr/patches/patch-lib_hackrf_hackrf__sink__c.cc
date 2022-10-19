$NetBSD: patch-lib_hackrf_hackrf__sink__c.cc,v 1.3 2022/10/19 18:38:29 adam Exp $

ISO C++17 does not allow 'register' storage class specifier.

--- lib/hackrf/hackrf_sink_c.cc.orig	2022-10-19 18:33:40.000000000 +0000
+++ lib/hackrf/hackrf_sink_c.cc
@@ -299,7 +299,7 @@ void convert_avx(const float* inbuf, int
 #elif USE_SSE2
 void convert_sse2(const float* inbuf, int8_t* outbuf,const unsigned int count)
 {
-  const register __m128 mulme = _mm_set_ps( 127.0f, 127.0f, 127.0f, 127.0f );
+  const __m128 mulme = _mm_set_ps( 127.0f, 127.0f, 127.0f, 127.0f );
   __m128 itmp1,itmp2,itmp3,itmp4;
   __m128i otmp1,otmp2,otmp3,otmp4;
 
