$NetBSD: patch-vm_ArrayBufferObject.cpp,v 1.1 2020/11/06 09:11:31 maya Exp $

PaX MPROTECT safety for NetBSD.

--- vm/ArrayBufferObject.cpp.orig	2020-03-05 20:57:04.000000000 +0000
+++ vm/ArrayBufferObject.cpp
@@ -179,9 +179,17 @@ void* js::MapBufferMemory(size_t mappedS
     return nullptr;
   }
 #else   // XP_WIN
+
+#ifdef PROT_MPROTECT
+  void* data =
+      MozTaggedAnonymousMmap(nullptr, mappedSize,
+                             PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                             MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#else
   void* data =
       MozTaggedAnonymousMmap(nullptr, mappedSize, PROT_NONE,
                              MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#endif
   if (data == MAP_FAILED) {
     liveBufferCount--;
     return nullptr;
