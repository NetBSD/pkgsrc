$NetBSD: patch-src_calibre_headless_fontconfig_database.cpp,v 1.2 2022/01/09 15:43:51 rhialto Exp $

Qt 5.15.0 has more languages in an array that Calibre tries to match,
and it checks with a STATIC_ASSERT.

--- src/calibre/headless/fontconfig_database.cpp.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/headless/fontconfig_database.cpp
@@ -295,7 +295,28 @@ static const char specialLanguages[][6] 
     "", // MasaramGondi
     "", // Nushu
     "", // Soyombo
-    "" // ZanabazarSquare
+    "", // ZanabazarSquare
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
+        // Unicode 12.1 additions
+    "", //    Script_Dogra,
+    "", //    Script_GunjalaGondi,
+    "", //    Script_HanifiRohingya,
+    "", //    Script_Makasar,
+    "", //    Script_Medefaidrin,
+    "", //    Script_OldSogdian,
+    "", //    Script_Sogdian,
+    "", //    Script_Elymaic,
+    "", //    Script_Nandinagari,
+    "", //    Script_NyiakengPuachueHmong,
+    "", //    Script_Wancho,
+
+        // Unicode 13.0 additions
+    "", //    Script_Chorasmian,
+    "", //    Script_DivesAkuru,
+    "", //    Script_KhitanSmallScript,
+    "", //    Script_Yezidi,
+#endif // Qt >= 5.15
+
 #else
     ""  // SignWriting
 #endif // Qt >= 5.11
