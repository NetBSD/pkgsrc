$NetBSD: patch-src_Qt_pc6001v.cpp,v 1.1 2020/06/10 10:39:57 tsutsui Exp $

- avoid Q_ASSERT() when LANG is not set on Qt 5.14.1
  that could return empty uiLanguages().

--- src/Qt/pc6001v.cpp.orig	2020-06-07 14:40:14.000000000 +0000
+++ src/Qt/pc6001v.cpp
@@ -38,7 +38,8 @@ int main( int argc, char *argv[] )
 #endif
 
 	QLocale locale;
-	QString lang = locale.uiLanguages()[0];
+	QStringList langs = locale.uiLanguages() << "C";
+	QString lang = langs.first();
 	QTranslator myappTranslator;
 
 	//表示言語が日本語でない場合は英語リソースを読み込む
