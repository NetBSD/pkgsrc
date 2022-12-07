$NetBSD: patch-src_plugins_clangformat_clangformatutils.cpp,v 1.1 2022/12/07 16:32:55 wiz Exp $

Fix build with llvm 15.
https://github.com/qt-creator/qt-creator/commit/b97c9494af2d4d6e53bcc87b588f21a4f445ef6f
and newer

--- src/plugins/clangformat/clangformatutils.cpp.orig	2021-11-03 11:14:14.000000000 +0000
+++ src/plugins/clangformat/clangformatutils.cpp
@@ -51,7 +51,10 @@ static clang::format::FormatStyle qtcSty
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
@@ -111,7 +114,11 @@ static clang::format::FormatStyle qtcSty
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
