$NetBSD: patch-lib_rubygems_uninstaller.rb,v 1.2 2014/02/19 15:50:53 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/uninstaller.rb.orig	2011-07-27 03:42:40.000000000 +0000
+++ lib/rubygems/uninstaller.rb
@@ -50,6 +50,11 @@ class Gem::Uninstaller
     @force_ignore      = options[:ignore]
     @bin_dir           = options[:bin_dir]
     @format_executable = options[:format_executable]
+    install_root = options[:install_root]
+    unless install_root.nil? or install_root.empty?
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
 
     # only add user directory if install_dir is not set
     @user_install = false
@@ -155,7 +160,11 @@ class Gem::Uninstaller
     unless remove then
       say "Executables and scripts will remain installed."
     else
-      bin_dir = @bin_dir || Gem.bindir(spec.base_dir)
+      bin_dir = @bin_dir || (Gem.bindir @gem_home, @install_root)
+
+      unless @install_root.nil? or @install_root.empty?
+        bindir = File.join(@install_root, bindir)
+      end
 
       raise Gem::FilePermissionError, bin_dir unless File.writable? bin_dir
 
