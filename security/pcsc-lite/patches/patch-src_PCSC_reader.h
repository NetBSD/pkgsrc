$NetBSD: patch-src_PCSC_reader.h,v 1.1 2012/12/14 23:50:36 pettai Exp $

Add NetBSD to apple/sun conditional.
This should be sent upstream.

--- src/PCSC/reader.h.orig	2011-06-22 06:38:16.000000000 +0000
+++ src/PCSC/reader.h
@@ -128,7 +128,7 @@
 
 /* Set structure elements aligment on bytes
  * http://gcc.gnu.org/onlinedocs/gcc/Structure_002dPacking-Pragmas.html */
-#if defined(__APPLE__) | defined(sun)
+#if defined(__APPLE__) | defined(sun) | defined(__NetBSD__)
 #pragma pack(1)
 #else
 #pragma pack(push, 1)
@@ -213,7 +213,7 @@ typedef struct {
 } PIN_PROPERTIES_STRUCTURE;
 
 /* restore default structure elements alignment */
-#if defined(__APPLE__) | defined(sun)
+#if defined(__APPLE__) | defined(sun) | defined(__NetBSD__)
 #pragma pack()
 #else
 #pragma pack(pop)
