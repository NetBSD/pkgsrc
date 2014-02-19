$NetBSD: patch-lib_rubygems.rb,v 1.3 2014/02/19 15:50:53 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2012-04-19 23:38:41.000000000 +0000
+++ lib/rubygems.rb
@@ -330,7 +330,10 @@ module Gem
   ##
   # The path where gem executables are to be installed.
 
-  def self.bindir(install_dir=Gem.dir)
+  def self.bindir(install_dir=Gem.dir, install_root=nil)
+    unless install_root.nil? or install_empty.nil?
+      install_dir = install_dir.sub(install_root, "")
+    end
     # TODO: move to Gem::Dirs
     return File.join install_dir, 'bin' unless
       install_dir.to_s == Gem.default_dir.to_s
@@ -622,12 +625,12 @@ module Gem
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
 
     if QUICKLOADER_SUCKAGE then
       $LOAD_PATH.each_with_index do |path, i|
@@ -821,6 +824,7 @@ module Gem
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(ConfigMap[:sitelibdir]) and
+       prefix != File.expand_path(ConfigMap[:vendorlibdir]) and
        prefix != File.expand_path(ConfigMap[:libdir]) and
        'lib' == File.basename(RUBYGEMS_DIR) then
       prefix
