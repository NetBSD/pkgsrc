$NetBSD: patch-vm_ArrayBufferObject.cpp,v 1.1 2020/11/10 11:27:10 nia Exp $

MPROTECT fix

--- vm/ArrayBufferObject.cpp.orig	2020-09-25 09:22:59.000000000 +0000
+++ vm/ArrayBufferObject.cpp
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
