$NetBSD: patch-cipher_bithelp.h,v 1.4 2014/01/13 11:44:27 obache Exp $

* NetBSD has bswap32 and bswap64 as macros.
  https://bugs.g10code.com/gnupg/issue1600

--- cipher/bithelp.h.orig	2013-12-09 07:48:50.000000000 +0000
+++ cipher/bithelp.h
@@ -39,9 +39,10 @@ static inline u32 ror(u32 x, int n)
 /* Byte swap for 32-bit and 64-bit integers.  If available, use compiler
    provided helpers.  */
 #ifdef HAVE_BUILTIN_BSWAP32
-# define bswap32 __builtin_bswap32
+# define _gcry_bswap32 __builtin_bswap32
 #else
-static inline u32 bswap32(u32 x)
+static inline u32
+_gcry_bswap32(u32 x)
 {
 	return ((rol(x, 8) & 0x00ff00ffL) | (ror(x, 8) & 0xff00ff00L));
 }
@@ -49,29 +50,30 @@ static inline u32 bswap32(u32 x)
 
 #ifdef HAVE_U64_TYPEDEF
 # ifdef HAVE_BUILTIN_BSWAP64
-#  define bswap64 __builtin_bswap64
+#  define _gcry_bswap64 __builtin_bswap64
 # else
-static inline u64 bswap64(u64 x)
+static inline u64
+_gcry_bswap64(u64 x)
 {
-	return ((u64)bswap32(x) << 32) | (bswap32(x >> 32));
+	return ((u64)_gcry_bswap32(x) << 32) | (_gcry_bswap32(x >> 32));
 }
 # endif
 #endif
 
 /* Endian dependent byte swap operations.  */
 #ifdef WORDS_BIGENDIAN
-# define le_bswap32(x) bswap32(x)
+# define le_bswap32(x) _gcry_bswap32(x)
 # define be_bswap32(x) ((u32)(x))
 # ifdef HAVE_U64_TYPEDEF
-#  define le_bswap64(x) bswap64(x)
+#  define le_bswap64(x) _gcry_bswap64(x)
 #  define be_bswap64(x) ((u64)(x))
 # endif
 #else
 # define le_bswap32(x) ((u32)(x))
-# define be_bswap32(x) bswap32(x)
+# define be_bswap32(x) _gcry_bswap32(x)
 # ifdef HAVE_U64_TYPEDEF
 #  define le_bswap64(x) ((u64)(x))
-#  define be_bswap64(x) bswap64(x)
+#  define be_bswap64(x) _gcry_bswap64(x)
 # endif
 #endif
 
