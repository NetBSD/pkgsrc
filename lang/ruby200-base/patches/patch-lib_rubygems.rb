$NetBSD: patch-lib_rubygems.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2013-06-21 16:16:31.000000000 +0000
+++ lib/rubygems.rb
@@ -286,7 +286,10 @@ module Gem
   ##
   # The path where gem executables are to be installed.
 
-  def self.bindir(install_dir=Gem.dir)
+  def self.bindir(install_dir=Gem.dir, install_root=nil)
+    unless install_root.nil?
+      install_dir = install_dir.sub(install_root, "")
+    end
     # TODO: move to Gem::Dirs
     return File.join install_dir, 'bin' unless
       install_dir.to_s == Gem.default_dir.to_s
@@ -546,12 +549,12 @@ module Gem
   ##
   # The index to insert activated gem paths into the $LOAD_PATH.
   #
-  # Defaults to the site lib directory unless gem_prelude.rb has loaded paths,
+  # Defaults to the vendor lib directory unless gem_prelude.rb has loaded paths,
   # then it inserts the activated gem's paths before the gem_prelude.rb paths
   # so you can override the gem_prelude.rb default $LOAD_PATH paths.
 
   def self.load_path_insert_index
-    index = $LOAD_PATH.index ConfigMap[:sitelibdir]
+    index = $LOAD_PATH.index ConfigMap[:vendorlibdir]
 
     index
   end
@@ -724,6 +727,7 @@ module Gem
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(ConfigMap[:sitelibdir]) and
+       prefix != File.expand_path(ConfigMap[:vendorlibdir]) and
        prefix != File.expand_path(ConfigMap[:libdir]) and
        'lib' == File.basename(RUBYGEMS_DIR) then
       prefix
