$NetBSD: patch-lib_rubygems.rb,v 1.1 2024/01/21 08:22:03 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems.rb.orig	2023-12-11 07:06:03.000000000 +0000
+++ lib/rubygems.rb
@@ -293,10 +293,16 @@ module Gem
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
@@ -560,7 +566,7 @@ An Array (#{env.inspect}) was passed in 
       return i if path.instance_variable_defined?(:@gem_prelude_index)
     end
 
-    index = $LOAD_PATH.index RbConfig::CONFIG["sitelibdir"]
+    index = $LOAD_PATH.index RbConfig::CONFIG["vendorlibdir"]
 
     index || 0
   end
@@ -736,6 +742,7 @@ An Array (#{env.inspect}) was passed in 
     prefix = File.dirname RUBYGEMS_DIR
 
     if prefix != File.expand_path(RbConfig::CONFIG["sitelibdir"]) &&
+       prefix != File.expand_path(RbConfig::CONFIG["vendorlibdir"]) &&
        prefix != File.expand_path(RbConfig::CONFIG["libdir"]) &&
        File.basename(RUBYGEMS_DIR) == "lib"
       prefix
