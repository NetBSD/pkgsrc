$NetBSD: patch-libvideogfx_utility_bitstream_bitreader.cc,v 1.1 2019/04/24 13:26:25 he Exp $

Instead of fixing precedence ("not an lvalue"), split operation like on x86.

--- libvideogfx/utility/bitstream/bitreader.cc.orig	2002-05-02 11:47:11.000000000 +0000
+++ libvideogfx/utility/bitstream/bitreader.cc
@@ -37,7 +37,8 @@ namespace videogfx {
   void BitReader::Refill()
   {
 #if WORDS_BIGENDIAN
-    uint32 val = *((uint32*)d_ptr)++;
+    uint32 val = *((uint32*)d_ptr);
+    d_ptr+=4;
 
     uint64 val64 = val;
     val64 <<= 64-32-d_bitsleft;
