$NetBSD: patch-lib_rubygems.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2022-11-24 10:20:31.000000000 +0000
+++ lib/rubygems.rb
@@ -299,10 +299,16 @@ module Gem
   ##
   # The path where gem executables are to be installed.
 
-  def self.bindir(install_dir=Gem.dir)
-    return File.join install_dir, "bin" unless
-      install_dir.to_s == Gem.default_dir.to_s
-    Gem.default_bindir
+  def self.bindir(install_dir=Gem.dir, install_root=nil)
+    if install_dir.to_s == Gem.default_dir.to_s
+      install_dir = Gem.default_bindir
+    else
+      install_dir = File.join install_dir, "bin"
+    end
+    unless install_root.nil? or install_root.empty?
+      install_dir = File.join install_root, install_dir
+    end
+    install_dir
   end
 
   ##
@@ -576,7 +582,7 @@ An Array (#{env.inspect}) was passed in 
       return i if path.instance_variable_defined?(:@gem_prelude_index)
     end
 
-    index = $LOAD_PATH.index RbConfig::CONFIG["sitelibdir"]
+    index = $LOAD_PATH.index RbConfig::CONFIG["vendorlibdir"]
 
     index || 0
   end
@@ -742,6 +748,7 @@ An Array (#{env.inspect}) was passed in 
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(RbConfig::CONFIG["sitelibdir"]) &&
+       prefix != File.expand_path(RbConfig::CONFIG["vendorlibdir"]) and
        prefix != File.expand_path(RbConfig::CONFIG["libdir"]) &&
        "lib" == File.basename(RUBYGEMS_DIR)
       prefix
