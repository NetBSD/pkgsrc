$NetBSD: patch-lib_rubygems.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2011-08-26 01:12:57.000000000 +0000
+++ lib/rubygems.rb
@@ -327,7 +327,10 @@ module Gem
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
@@ -619,12 +622,12 @@ module Gem
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
@@ -799,6 +802,7 @@ module Gem
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(ConfigMap[:sitelibdir]) and
+       prefix != File.expand_path(ConfigMap[:vendorlibdir]) and
        prefix != File.expand_path(ConfigMap[:libdir]) and
        'lib' == File.basename(RUBYGEMS_DIR) then
       prefix
