$NetBSD: patch-lib_rubygems_commands_setup__command.rb,v 1.2 2026/09/16 14:08:24 taca Exp $

* Make sure to setup under DESTDIR.

--- lib/rubygems/commands/setup_command.rb.orig	2026-09-14 23:54:56.000000000 +0000
+++ lib/rubygems/commands/setup_command.rb
@@ -172,7 +172,7 @@ By default, this RubyGems will install g
 
     uninstall_old_gemcutter
 
-    documentation_success = install_rdoc
+    documentation_success = install_rdoc install_destdir
 
     say
     if @verbose
@@ -295,11 +295,15 @@ By default, this RubyGems will install g
     end
   end
 
-  def install_rdoc
+  def install_rdoc(install_destdir)
     gem_doc_dir = File.join Gem.dir, "doc"
     rubygems_name = "rubygems-#{Gem::VERSION}"
     rubygems_doc_dir = File.join gem_doc_dir, rubygems_name
 
+    unless install_destdir.empty?
+      FileUtils.mkdir_p gem_doc_dir unless File.exist?(gem_doc_dir)
+    end
+
     begin
       Gem.ensure_gem_subdirectories Gem.dir
     rescue SystemCallError
