$NetBSD: patch-core_utils.rb,v 1.3 2012/03/02 06:34:35 obache Exp $

* use included escape library instead of system one.

--- core/utils.rb.orig	2012-02-14 15:07:52.000000000 +0000
+++ core/utils.rb
@@ -32,7 +32,7 @@ Dir::chdir(File::dirname(__FILE__))
 ['.', 'lib', 'miku'].each{|path|
   $LOAD_PATH.push(File.expand_path(File.join(Dir.pwd, path)))
 }
-miquire :lib, 'escape'
+miquire :lib, 'miku/escape'
 miquire :lib, 'lazy'
 
 # すべてのクラスにメモ化機能を
