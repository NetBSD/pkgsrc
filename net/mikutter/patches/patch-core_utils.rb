$NetBSD: patch-core_utils.rb,v 1.1 2011/06/19 04:19:56 obache Exp $

* use included escape library instead of system one.

--- core/utils.rb.orig	2011-06-12 14:01:26.000000000 +0000
+++ core/utils.rb
@@ -83,7 +83,7 @@ def file_or_directory_require(rb)
     require rb end end
 
 Dir::chdir(File::dirname(__FILE__))
-miquire :lib, 'escape'
+miquire :lib, 'miku/escape'
 miquire :lib, 'lazy'
 
 # すべてのクラスにメモ化機能を
