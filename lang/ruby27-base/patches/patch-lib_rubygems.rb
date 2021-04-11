$NetBSD: patch-lib_rubygems.rb,v 1.2 2021/04/11 12:32:03 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2021-04-05 12:39:38.000000000 +0000
+++ lib/rubygems.rb
@@ -311,10 +311,16 @@ module Gem
   ##
   # The path where gem executables are to be installed.
 
-  def self.bindir(install_dir=Gem.dir)
-    return File.join install_dir, 'bin' unless
-      install_dir.to_s == Gem.default_dir.to_s
-    Gem.default_bindir
+  def self.bindir(install_dir=Gem.dir, install_root=nil)
+    if install_dir.to_s == Gem.default_dir.to_s
+      install_dir = Gem.default_bindir
+    else
+      install_dir = File.join install_dir, 'bin'
+    end
+    unless install_root.nil? or install_root.empty?
+      install_dir = File.join install_root, install_dir
+    end
+    install_dir
   end
 
   ##
@@ -657,7 +663,7 @@ An Array (#{env.inspect}) was passed in 
       return i if path.instance_variable_defined?(:@gem_prelude_index)
     end
 
-    index = $LOAD_PATH.index RbConfig::CONFIG['sitelibdir']
+    index = $LOAD_PATH.index RbConfig::CONFIG['vendordir']
 
     index || 0
   end
@@ -849,6 +855,7 @@ An Array (#{env.inspect}) was passed in 
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(RbConfig::CONFIG['sitelibdir']) and
+       prefix != File.expand_path(RbConfig::CONFIG['vendordir']) and
        prefix != File.expand_path(RbConfig::CONFIG['libdir']) and
        'lib' == File.basename(RUBYGEMS_DIR)
       prefix
