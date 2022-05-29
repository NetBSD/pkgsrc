$NetBSD: patch-src_libcryptobox_cryptobox.c,v 1.3 2022/05/29 19:21:46 gavan Exp $

--- src/libcryptobox/cryptobox.c.orig	2021-11-01 14:33:30.000000000 +0000
+++ src/libcryptobox/cryptobox.c
@@ -118,7 +118,7 @@ rspamd_cryptobox_test_instr (gint instr)
 	}
 
 	switch (instr) {
-#ifdef HAVE_SSE2
+#if defined HAVE_SSE2 && defined(__x86_64__)
 	case CPUID_SSE2:
 		__asm__ volatile ("psubb %xmm0, %xmm0");
 		break;
@@ -146,7 +146,7 @@ rspamd_cryptobox_test_instr (gint instr)
 		__asm__ volatile ("pcmpeqq %xmm0, %xmm0");
 		break;
 #endif
-#ifdef HAVE_SSE42
+#if defined HAVE_SSE42 && defined(__x86_64__)
 	case CPUID_SSE42:
 		__asm__ volatile ("pushq %rax\n"
 				"xorq %rax, %rax\n"
