$NetBSD: patch-js_src_vm_ArrayBufferObject.cpp,v 1.1 2020/12/05 12:03:26 nia Exp $

PaX MPROTECT safety for NetBSD

--- js/src/vm/ArrayBufferObject.cpp.orig	2020-11-04 10:52:03.000000000 +0000
+++ js/src/vm/ArrayBufferObject.cpp
@@ -164,9 +164,17 @@ void* js::MapBufferMemory(size_t mappedS
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
     return nullptr;
   }
