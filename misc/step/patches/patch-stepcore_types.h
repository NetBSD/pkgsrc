$NetBSD: patch-stepcore_types.h,v 1.1 2026/01/25 00:38:18 markd Exp $

Fix compile with Qt 6.11
https://github.com/KDE/step/commit/0d41eaae3820d1a7c346f6ce81b940f199229eba

--- stepcore/types.h.orig	2025-10-31 23:35:39.000000000 +0000
+++ stepcore/types.h
@@ -38,7 +38,7 @@ struct Color
 
 template<> inline QString typeToString(const Color& v)
 {
-    return QStringLiteral("#%1").arg(v, 8, 16, QLatin1Char('0'));
+    return QStringLiteral("#%1").arg(v.value, 8, 16, QLatin1Char('0'));
 }
 
 template<> inline Color stringToType(const QString& s, bool *ok)
