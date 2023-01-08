$NetBSD: patch-lib_manpages_install.rb,v 1.1.2.2 2023/01/08 15:57:24 bsiegert Exp $

Handle --install-root option.

--- lib/manpages/install.rb.orig	2022-12-29 07:41:29.224449401 +0000
+++ lib/manpages/install.rb
@@ -2,10 +2,11 @@ require "fileutils"
 
 module Manpages
   class Install
-    def initialize(gem_spec, gem_dir, target_dir)
+    def initialize(gem_spec, gem_dir, target_dir, install_root)
       @gem_spec   = gem_spec
       @gem_dir    = gem_dir
       @target_dir = target_dir
+      @install_root = install_root
     end
 
     def install_manpages
@@ -24,6 +25,7 @@ module Manpages
       man_target_file = ManFiles.new(@gem_dir, @target_dir).man_file_path(file)
       return if man_target_file.exist?
 
+      file = file.to_s.delete_prefix @install_root unless @install_root.nil?
       begin
         FileUtils.mkdir_p(man_target_file.dirname)
         FileUtils.ln_s(file, man_target_file, force: true)
