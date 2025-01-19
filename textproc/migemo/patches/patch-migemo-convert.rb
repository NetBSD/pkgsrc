$NetBSD: patch-migemo-convert.rb,v 1.2 2025/01/19 11:24:44 taca Exp $

* Set default external encoding to EUC-JP.
* Add specifying script encoding to EUC-JP.
* Explictly set encoding of standard input to EUC-JP.

--- migemo-convert.rb.orig	2003-05-26 06:55:22.000000000 +0000
+++ migemo-convert.rb
@@ -1,3 +1,4 @@
+# coding: euc-jp
 #
 # Ruby/Migemo - a library for Japanese incremental search.
 #
@@ -10,11 +11,11 @@
 #
 # NOTE: Ruby/Migemo can work only with EUC_JP encoding. ($KCODE="e")
 #
+Encoding.default_external = Encoding::EUC_JP
 
 #
 # Convert a SKK's dictionary into Migemo's.
 #
-$KCODE= "e"
 require 'romkan'
 
 HIRAGANA = "[¤¡-¤ó¡¼¡Á]"
