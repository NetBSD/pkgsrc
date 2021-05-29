$NetBSD: patch-miner.h,v 1.1 2021/05/29 19:30:57 khorben Exp $

Fix build on Aarch64 (from upstream)

--- miner.h.orig	2020-06-25 15:02:57.000000000 +0000
+++ miner.h
@@ -137,7 +137,7 @@ void sha256_transform(uint32_t *state, c
 void sha256d(unsigned char *hash, const unsigned char *data, int len);
 
 #ifdef USE_ASM
-#if defined(__ARM_NEON__) || defined(__ALTIVEC__) || defined(__i386__) || defined(__x86_64__)
+#if (defined(__APCS_32__) && defined(__ARM_NEON__)) || defined(__ALTIVEC__) || defined(__i386__) || defined(__x86_64__)
 #define HAVE_SHA256_4WAY 1
 int sha256_use_4way();
 void sha256_init_4way(uint32_t *state);
