$NetBSD: patch-cipher_bithelp.h,v 1.3 2014/01/08 09:39:45 obache Exp $

* NetBSD has bswap32 and bswap64 as macros.
  https://bugs.g10code.com/gnupg/issue1600

--- cipher/bithelp.h.orig	2013-12-09 07:48:50.000000000 +0000
+++ cipher/bithelp.h
@@ -40,7 +40,7 @@ static inline u32 ror(u32 x, int n)
    provided helpers.  */
 #ifdef HAVE_BUILTIN_BSWAP32
 # define bswap32 __builtin_bswap32
-#else
+#elif !defined(__NetBSD__) && !defined(bswap32)
 static inline u32 bswap32(u32 x)
 {
 	return ((rol(x, 8) & 0x00ff00ffL) | (ror(x, 8) & 0xff00ff00L));
@@ -50,7 +50,7 @@ static inline u32 bswap32(u32 x)
 #ifdef HAVE_U64_TYPEDEF
 # ifdef HAVE_BUILTIN_BSWAP64
 #  define bswap64 __builtin_bswap64
-# else
+# elif !defined(__NetBSD__) && !defined(bswap64)
 static inline u64 bswap64(u64 x)
 {
 	return ((u64)bswap32(x) << 32) | (bswap32(x >> 32));
