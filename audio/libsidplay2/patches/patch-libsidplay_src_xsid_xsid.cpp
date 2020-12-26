$NetBSD: patch-libsidplay_src_xsid_xsid.cpp,v 1.1 2020/12/26 19:54:14 nat Exp $
Requires unsigned type to avoid overflow.
Express data in hex.
--- libsidplay/src/xsid/xsid.cpp.orig	2004-06-14 20:08:02.000000000 +0000
+++ libsidplay/src/xsid/xsid.cpp
@@ -94,10 +94,10 @@ const int8_t XSID::sampleConvertTable[16
     '\x08', '\x19', '\x2a', '\x3b', '\x4c', '\x5d', '\x6e', '\x7f'
 };
 */
-const int8_t XSID::sampleConvertTable[16] =
+const uint8_t XSID::sampleConvertTable[16] =
 {
-    '\x80', '\x94', '\xa9', '\xbc', '\xce', '\xe1', '\xf2', '\x03',
-    '\x1b', '\x2a', '\x3b', '\x49', '\x58', '\x66', '\x73', '\x7f'
+    0x80, 0x94, 0xa9, 0xbc, 0xce, 0xe1, 0xf2, 0x03,
+    0x1b, 0x2a, 0x3b, 0x49, 0x58, 0x66, 0x73, 0x7f
 };
 
 const char *XSID::credit =
