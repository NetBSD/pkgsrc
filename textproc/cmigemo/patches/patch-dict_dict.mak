$NetBSD: patch-dict_dict.mak,v 1.1.1.1 2012/01/21 13:38:41 obache Exp $

* generage UTF-8 dict and dat files for all platforms
  http://code.google.com/p/cmigemo/source/detail?spec=svn4e16f44f91df858b41c39af25798214b1c995a7a&r=55d9df600d6b83d16c1e61d4f201adfb81a1f5a4

--- dict/dict.mak.orig	2011-02-27 10:45:40.000000000 +0000
+++ dict/dict.mak
@@ -2,7 +2,7 @@
 #
 # 辞書ファイルのメンテナンス
 # 
-# Written By:  MURAOKA Taro <koron@tka.att.ne.jp>
+# Written By:  MURAOKA Taro <koron.kaoriya@gmail.com>
 
 DICT 		= migemo-dict
 DICT_BASE	= base-dict
@@ -77,22 +77,27 @@ msvc:		cp932 utf-8
 ##############################################################################
 # for Borland C 5
 #
-bc5:		cp932
+bc5:		cp932 utf-8
 
 ##############################################################################
 # for Cygwin
 #
-cyg:		euc-jp
+cyg:		euc-jp utf-8
+
+##############################################################################
+# for MinGW
+#
+mingw:		cp932 utf-8
 
 ##############################################################################
 # for GNU/gcc(Linux他)
 #
-gcc:		euc-jp
+gcc:		euc-jp utf-8
 
 ##############################################################################
 # for MacOS X
 #
-osx:		euc-jp
+osx:		euc-jp utf-8
 
 ##############################################################################
 # Cleaning
