$NetBSD: patch-lib_rubygems_uninstaller.rb,v 1.2 2014/02/19 15:52:05 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/uninstaller.rb.orig	2012-12-19 07:19:10.000000000 +0000
+++ lib/rubygems/uninstaller.rb
@@ -51,6 +51,11 @@ class Gem::Uninstaller
     @force_ignore      = options[:ignore]
     @bin_dir           = options[:bin_dir]
     @format_executable = options[:format_executable]
+    install_root = options[:install_root]
+    unless install_root.nil? or install_root.empty?
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
 
     # Indicate if development dependencies should be checked when
     # uninstalling. (default: false)
@@ -199,7 +204,11 @@ class Gem::Uninstaller
              end
 
     if remove then
-      bin_dir = @bin_dir || Gem.bindir(spec.base_dir)
+      bin_dir = @bin_dir || (Gem.bindir @gem_home, @install_root)
+
+      unless @install_root.nil? or @install_root.empty?
+        bindir = File.join(@install_root, bindir)
+      end
 
       raise Gem::FilePermissionError, bin_dir unless File.writable? bin_dir
 
