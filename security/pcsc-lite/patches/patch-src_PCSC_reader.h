$NetBSD: patch-src_PCSC_reader.h,v 1.2 2014/10/01 16:27:03 gdt Exp $

Add NetBSD to apple/sun conditional.
This should be sent upstream.

--- src/PCSC/reader.h.orig	2014-02-14 16:15:44.000000000 +0000
+++ src/PCSC/reader.h
@@ -155,7 +155,7 @@ THIS SOFTWARE, EVEN IF ADVISED OF THE PO
 
 /* Set structure elements aligment on bytes
  * http://gcc.gnu.org/onlinedocs/gcc/Structure_002dPacking-Pragmas.html */
-#if defined(__APPLE__) | defined(sun)
+#if defined(__APPLE__) | defined(sun) | defined(__NetBSD__)
 #pragma pack(1)
 #else
 #pragma pack(push, 1)
@@ -252,7 +252,7 @@ typedef struct {
 } PIN_PROPERTIES_STRUCTURE;
 
 /* restore default structure elements alignment */
-#if defined(__APPLE__) | defined(sun)
+#if defined(__APPLE__) | defined(sun) | defined(__NetBSD__)
 #pragma pack()
 #else
 #pragma pack(pop)
