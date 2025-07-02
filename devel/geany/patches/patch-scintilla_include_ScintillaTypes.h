$NetBSD: patch-scintilla_include_ScintillaTypes.h,v 1.1 2025/07/02 02:26:09 markd Exp $

define 'intptr_t'

--- scintilla/include/ScintillaTypes.h.orig	2023-10-19 16:09:27.000000000 +0000
+++ scintilla/include/ScintillaTypes.h
@@ -11,6 +11,8 @@
 #ifndef SCINTILLATYPES_H
 #define SCINTILLATYPES_H
 
+#include <cstdint>
+
 namespace Scintilla {
 
 // Enumerations
