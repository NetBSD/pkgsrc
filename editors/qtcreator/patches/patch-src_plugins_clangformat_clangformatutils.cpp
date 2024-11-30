$NetBSD: patch-src_plugins_clangformat_clangformatutils.cpp,v 1.4 2024/11/30 17:47:50 nros Exp $

Fix build with llvm 16.
https://github.com/qt-creator/qt-creator/commit/b97c9494af2d4d6e53bcc87b588f21a4f445ef6f
and newer

Fix build with LLVM 17
https://github.com/qt-creator/qt-creator/commit/9ad9e49ccf6e0d7f4ba5765cff3af63fbbed60e8

Fix warnings with LLVM 18
https://github.com/qt-creator/qt-creator/commit/7457b623125f4bcdb7941769a385cfbfc0dcbf2b

Fix build with LLVM 19
https://github.com/qt-creator/qt-creator/commit/f175ec933f1c5c5d7a345edbaacc8ff90202aee2

--- src/plugins/clangformat/clangformatutils.cpp.orig	2021-11-03 10:14:14.000000000 +0000
+++ src/plugins/clangformat/clangformatutils.cpp
@@ -51,7 +51,13 @@ static clang::format::FormatStyle qtcSty
     style.Language = FormatStyle::LK_Cpp;
     style.AccessModifierOffset = -4;
     style.AlignAfterOpenBracket = FormatStyle::BAS_Align;
-#if LLVM_VERSION_MAJOR >= 12
+#if LLVM_VERSION_MAJOR >= 18
+    style.AlignConsecutiveAssignments = {false, false, false, false, false, false};
+    style.AlignConsecutiveDeclarations = {false, false, false, false, false, false};
+#elif LLVM_VERSION_MAJOR >= 15
+    style.AlignConsecutiveAssignments = {false, false, false, false, false};
+    style.AlignConsecutiveDeclarations = {false, false, false, false, false};
+#elif LLVM_VERSION_MAJOR >= 12
     style.AlignConsecutiveAssignments = FormatStyle::ACS_None;
     style.AlignConsecutiveDeclarations = FormatStyle::ACS_None;
 #else
@@ -64,7 +70,11 @@ static clang::format::FormatStyle qtcSty
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
@@ -111,7 +121,11 @@ static clang::format::FormatStyle qtcSty
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
@@ -131,7 +145,11 @@ static clang::format::FormatStyle qtcSty
     style.IndentWrappedFunctionNames = false;
     style.JavaScriptQuotes = FormatStyle::JSQS_Leave;
     style.JavaScriptWrapImports = true;
+#if LLVM_VERSION_MAJOR >= 19
+    style.KeepEmptyLines = {false, false, false}
+#else
     style.KeepEmptyLinesAtTheStartOfBlocks = false;
+#endif
     // Do not add QT_BEGIN_NAMESPACE/QT_END_NAMESPACE as this will indent lines in between.
     style.MacroBlockBegin = "";
     style.MacroBlockEnd = "";
@@ -154,12 +172,18 @@ static clang::format::FormatStyle qtcSty
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
     style.SpaceBeforeParens = FormatStyle::SBPO_ControlStatements;
+#if LLVM_VERSION_MAJOR < 17
     style.SpaceInEmptyParentheses = false;
+#endif
     style.SpacesBeforeTrailingComments = 1;
 #if LLVM_VERSION_MAJOR >= 13
     style.SpacesInAngles = FormatStyle::SIAS_Never;
@@ -167,8 +191,12 @@ static clang::format::FormatStyle qtcSty
     style.SpacesInAngles = false;
 #endif
     style.SpacesInContainerLiterals = false;
+#if LLVM_VERSION_MAJOR >= 17
+    style.SpacesInParens = FormatStyle::SIPO_Never;
+#else
     style.SpacesInCStyleCastParentheses = false;
     style.SpacesInParentheses = false;
+#endif
     style.SpacesInSquareBrackets = false;
     style.StatementMacros.emplace_back("Q_OBJECT");
     style.StatementMacros.emplace_back("QT_BEGIN_NAMESPACE");
