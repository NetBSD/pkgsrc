$NetBSD: patch-src_plugins_clangformat_clangformatutils.cpp,v 1.2 2023/05/11 13:30:17 nikita Exp $

Fix build with llvm 16.
https://github.com/qt-creator/qt-creator/commit/b97c9494af2d4d6e53bcc87b588f21a4f445ef6f
and newer

--- src/plugins/clangformat/clangformatutils.cpp.orig	2021-11-03 11:14:14.000000000 +0100
+++ src/plugins/clangformat/clangformatutils.cpp	2023-05-11 15:20:21.554698126 +0200
@@ -51,7 +51,10 @@
     style.Language = FormatStyle::LK_Cpp;
     style.AccessModifierOffset = -4;
     style.AlignAfterOpenBracket = FormatStyle::BAS_Align;
-#if LLVM_VERSION_MAJOR >= 12
+#if LLVM_VERSION_MAJOR >= 15
+    style.AlignConsecutiveAssignments = {false, false, false, false, false};
+    style.AlignConsecutiveDeclarations = {false, false, false, false, false};
+#elif LLVM_VERSION_MAJOR >= 12
     style.AlignConsecutiveAssignments = FormatStyle::ACS_None;
     style.AlignConsecutiveDeclarations = FormatStyle::ACS_None;
 #else
@@ -64,7 +67,11 @@
 #else
     style.AlignOperands = true;
 #endif
+#if LLVM_VERSION_MAJOR >= 16
+    style.AlignTrailingComments = {FormatStyle::TCAS_Always, 0};
+#else
     style.AlignTrailingComments = true;
+#endif
     style.AllowAllParametersOfDeclarationOnNextLine = true;
 #if LLVM_VERSION_MAJOR >= 10
     style.AllowShortBlocksOnASingleLine = FormatStyle::SBS_Never;
@@ -111,7 +118,11 @@
     style.ColumnLimit = 100;
     style.CommentPragmas = "^ IWYU pragma:";
     style.CompactNamespaces = false;
+#if LLVM_VERSION_MAJOR >= 15
+    style.PackConstructorInitializers = FormatStyle::PCIS_BinPack;
+#else
     style.ConstructorInitializerAllOnOneLineOrOnePerLine = false;
+#endif
     style.ConstructorInitializerIndentWidth = 4;
     style.ContinuationIndentWidth = 4;
     style.Cpp11BracedListStyle = true;
@@ -154,7 +165,11 @@
 #else
     style.SortIncludes = true;
 #endif
+#if LLVM_VERSION_MAJOR >= 16
+    style.SortUsingDeclarations = FormatStyle::SUD_Lexicographic;
+#else
     style.SortUsingDeclarations = true;
+#endif
     style.SpaceAfterCStyleCast = true;
     style.SpaceAfterTemplateKeyword = false;
     style.SpaceBeforeAssignmentOperators = true;
