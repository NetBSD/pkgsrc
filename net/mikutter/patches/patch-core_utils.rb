$NetBSD: patch-core_utils.rb,v 1.2 2011/11/06 07:49:38 obache Exp $

* use included escape library instead of system one.

--- core/utils.rb.orig	2011-10-02 11:08:04.000000000 +0000
+++ core/utils.rb
@@ -35,7 +35,7 @@ if RUBY_VERSION >= '1.9.2'
     $LOAD_PATH.push(File.expand_path(File.join(Dir.pwd, path)))
   }
 end
-miquire :lib, 'escape'
+miquire :lib, 'miku/escape'
 miquire :lib, 'lazy'
 
 # すべてのクラスにメモ化機能を
