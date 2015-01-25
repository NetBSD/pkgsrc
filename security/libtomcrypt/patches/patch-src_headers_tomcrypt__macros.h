$NetBSD: patch-src_headers_tomcrypt__macros.h,v 1.1 2015/01/25 13:13:51 joerg Exp $

clang doesn't allow non-constant arguments for "I" constraints.
Just use the C version, it will get optimised to rotate anyway.

--- src/headers/tomcrypt_macros.h.orig	2015-01-24 16:35:36.000000000 +0000
+++ src/headers/tomcrypt_macros.h
@@ -242,7 +242,7 @@ asm __volatile__ (             \
 #define RORc(x,n) _lrotr(x,n)
 #define ROLc(x,n) _lrotl(x,n)
 
-#elif !defined(__STRICT_ANSI__) && defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)) && !defined(INTEL_CC) && !defined(LTC_NO_ASM)
+#elif !defined(__STRICT_ANSI__) && defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__)) && !defined(INTEL_CC) && !defined(LTC_NO_ASM) && !defined(__clang__)
 
 static inline unsigned ROL(unsigned word, int i)
 {
@@ -341,7 +341,7 @@ static inline unsigned RORc(unsigned wor
 
 
 /* 64-bit Rotates */
-#if !defined(__STRICT_ANSI__) && defined(__GNUC__) && defined(__x86_64__) && !defined(LTC_NO_ASM)
+#if !defined(__STRICT_ANSI__) && defined(__GNUC__) && defined(__x86_64__) && !defined(LTC_NO_ASM) && !defined(__clang__)
 
 static inline unsigned long ROL64(unsigned long word, int i)
 {
