$NetBSD: patch-migemo-index.rb,v 1.2 2025/01/19 11:24:44 taca Exp $

* Add specifying script encoding to EUC-JP.
* Use bytesize instead of length.

--- migemo-index.rb.orig	2003-05-26 06:45:53.000000000 +0000
+++ migemo-index.rb
@@ -1,3 +1,4 @@
+# coding: euc-jp
 #
 # Ruby/Migemo - a library for Japanese incremental search.
 #
@@ -10,6 +11,7 @@
 #
 # NOTE: Ruby/Migemo can work only with EUC_JP encoding. ($KCODE="e")
 #
+Encoding.default_external = Encoding::EUC_JP
 
 #
 # Index Migemo's dictionary.
@@ -19,5 +21,5 @@ while line = gets
   unless line =~ /^;/
     print [offset].pack("N")
   end
-  offset += line.length
+  offset += line.bytesize
 end
