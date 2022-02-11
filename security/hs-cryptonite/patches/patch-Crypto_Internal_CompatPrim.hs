$NetBSD: patch-Crypto_Internal_CompatPrim.hs,v 1.1 2022/02/11 13:10:15 pho Exp $

Fix build on GHC 9.2:
https://github.com/haskell-crypto/cryptonite/pull/354

--- Crypto/Internal/CompatPrim.hs.orig	2022-02-07 13:27:20.338888456 +0000
+++ Crypto/Internal/CompatPrim.hs
@@ -31,7 +31,11 @@ import Data.Memory.Endian (getSystemEndi
 -- | Byteswap Word# to or from Big Endian
 --
 -- On a big endian machine, this function is a nop.
+#if MIN_VERSION_base(4,16,0)
+be32Prim :: Word32# -> Word32#
+#else
 be32Prim :: Word# -> Word#
+#endif
 #ifdef ARCH_IS_LITTLE_ENDIAN
 be32Prim = byteswap32Prim
 #elif defined(ARCH_IS_BIG_ENDIAN)
@@ -43,7 +47,11 @@ be32Prim w = if getSystemEndianness == L
 -- | Byteswap Word# to or from Little Endian
 --
 -- On a little endian machine, this function is a nop.
+#if MIN_VERSION_base(4,16,0)
+le32Prim :: Word32# -> Word32#
+#else
 le32Prim :: Word# -> Word#
+#endif
 #ifdef ARCH_IS_LITTLE_ENDIAN
 le32Prim w = w
 #elif defined(ARCH_IS_BIG_ENDIAN)
@@ -54,6 +62,10 @@ le32Prim w = if getSystemEndianness == L
 
 -- | Simple compatibility for byteswap the lower 32 bits of a Word#
 -- at the primitive level
+#if MIN_VERSION_base(4,16,0)
+byteswap32Prim :: Word32# -> Word32#
+byteswap32Prim w = wordToWord32# (byteSwap32# (word32ToWord# w))
+#else
 byteswap32Prim :: Word# -> Word#
 #if __GLASGOW_HASKELL__ >= 708
 byteswap32Prim w = byteSwap32# w
@@ -65,6 +77,7 @@ byteswap32Prim w =
         !d = and# (uncheckedShiftRL# w 24#) 0x000000ff##
      in or# a (or# b (or# c d))
 #endif
+#endif
 
 -- | Combine 4 word8 [a,b,c,d] to a word32 representing [a,b,c,d]
 convert4To32 :: Word# -> Word# -> Word# -> Word#
