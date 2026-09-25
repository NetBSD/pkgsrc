$NetBSD: patch-source_core_slang-platform.cpp,v 1.1 2026/09/25 17:16:20 ktnb Exp $

Fix missing dylibs on Darwin

--- source/core/slang-platform.cpp.orig	2026-09-25 15:20:55.776172514 +0000
+++ source/core/slang-platform.cpp
@@ -322,6 +322,13 @@ SLANG_COMPILE_TIME_ASSERT(E_OUTOFMEMORY
         platformFileName = nullptr;
     const auto mode = RTLD_NOW | RTLD_LOCAL | (isUnclosable ? RTLD_NODELETE : 0);
     void* h = dlopen(platformFileName, mode);
+#if defined(__APPLE__)
+    if (!h && platformFileName && !strchr(platformFileName, '/'))
+    {
+        String rel = String("@loader_path/") + platformFileName;
+        h = dlopen(rel.getBuffer(), mode);
+    }
+#endif
     if (!h)
     {
 #if 0
