$NetBSD: patch-src_plugins_clangformat_clangformatbaseindenter.cpp,v 1.2 2024/11/30 17:47:50 nros Exp $

Fix build with LLVM 16
https://github.com/qt-creator/qt-creator/commit/e20bdfae4de90401a518135bc22958549dceda66
https://github.com/qt-creator/qt-creator/commit/f4545807defdfb493c1d66a19430a69d81afa40b

--- src/plugins/clangformat/clangformatbaseindenter.cpp.orig	2023-05-11 14:22:23.741477809 +0200
+++ src/plugins/clangformat/clangformatbaseindenter.cpp	2023-05-11 14:29:29.745830013 +0200
@@ -47,11 +47,19 @@
 #else
     style.SortIncludes = false;
 #endif
+#if LLVM_VERSION_MAJOR >= 16
+    style.SortUsingDeclarations = clang::format::FormatStyle::SUD_Never;
+#else
     style.SortUsingDeclarations = false;
+#endif
 
     // This is a separate pass, don't do it unless it's the full formatting.
     style.FixNamespaceComments = false;
+#if LLVM_VERSION_MAJOR >= 16
+    style.AlignTrailingComments = {clang::format::FormatStyle::TCAS_Never, 0};
+#else
     style.AlignTrailingComments = false;
+#endif
 
     if (replacementsToKeep == ReplacementsToKeep::IndentAndBefore)
         return;
