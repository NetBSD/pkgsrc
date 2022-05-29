$NetBSD: patch-src_libcryptobox_chacha20_chacha.c,v 1.1 2022/05/29 19:21:46 gavan Exp $

--- src/libcryptobox/chacha20/chacha.c.orig	2021-11-01 14:33:30.000000000 +0000
+++ src/libcryptobox/chacha20/chacha.c
@@ -52,15 +52,15 @@ typedef struct chacha_impl_t {
 #define CHACHA_IMPL(cpuflags, desc, ext) \
 		{(cpuflags), desc, chacha_##ext, xchacha_##ext, chacha_blocks_##ext, hchacha_##ext}
 
-#if defined(HAVE_AVX2)
+#if defined(HAVE_AVX2) && defined(__x86_64__)
 	CHACHA_DECLARE(avx2)
 	#define CHACHA_AVX2 CHACHA_IMPL(CPUID_AVX2, "avx2", avx2)
 #endif
-#if defined(HAVE_AVX)
+#if defined(HAVE_AVX) && defined(__x86_64__)
 	CHACHA_DECLARE(avx)
 	#define CHACHA_AVX CHACHA_IMPL(CPUID_AVX, "avx", avx)
 #endif
-#if defined(HAVE_SSE2)
+#if defined(HAVE_SSE2) && defined(__x86_64__)
 	CHACHA_DECLARE(sse2)
 	#define CHACHA_SSE2 CHACHA_IMPL(CPUID_SSE2, "sse2", sse2)
 #endif
@@ -70,13 +70,13 @@ CHACHA_DECLARE(ref)
 
 static const chacha_impl_t chacha_list[] = {
 	CHACHA_GENERIC,
-#if defined(CHACHA_AVX2)
+#if defined(CHACHA_AVX2) && defined(__x86_64__)
 	CHACHA_AVX2,
 #endif
-#if defined(CHACHA_AVX)
+#if defined(CHACHA_AVX) && defined(__x86_64__)
 	CHACHA_AVX,
 #endif
-#if defined(CHACHA_SSE2)
+#if defined(CHACHA_SSE2) && defined(__x86_64__)
 	CHACHA_SSE2
 #endif
 };
