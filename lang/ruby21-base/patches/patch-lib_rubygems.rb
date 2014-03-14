$NetBSD: patch-lib_rubygems.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2014-02-06 02:59:36.000000000 +0000
+++ lib/rubygems.rb
@@ -257,7 +257,10 @@ module Gem
   ##
   # The path where gem executables are to be installed.
 
-  def self.bindir(install_dir=Gem.dir)
+  def self.bindir(install_dir=Gem.dir, install_root=nil)
+    unless install_root.nil? or install_root.empty?
+      install_dir = install_dir.sub(install_root, "")
+    end
     return File.join install_dir, 'bin' unless
       install_dir.to_s == Gem.default_dir.to_s
     Gem.default_bindir
@@ -572,7 +575,7 @@ module Gem
   # gem's paths are inserted before site lib directory by default.
 
   def self.load_path_insert_index
-    index = $LOAD_PATH.index RbConfig::CONFIG['sitelibdir']
+    index = $LOAD_PATH.index RbConfig::CONFIG['vendorlibdir']
 
     index
   end
@@ -743,7 +746,7 @@ module Gem
   def self.prefix
     prefix = File.dirname RUBYGEMS_DIR
 
-    if prefix != File.expand_path(RbConfig::CONFIG['sitelibdir']) and
+    if prefix != File.expand_path(RbConfig::CONFIG['vendorlibdir']) and
        prefix != File.expand_path(RbConfig::CONFIG['libdir']) and
        'lib' == File.basename(RUBYGEMS_DIR) then
       prefix
