$NetBSD: patch-lib_rubygems_commands_setup__command.rb,v 1.2 2022/11/26 13:02:49 taca Exp $

* Make sure to setup under DESTDIR.

--- lib/rubygems/commands/setup_command.rb.orig	2022-11-24 10:20:31.000000000 +0000
+++ lib/rubygems/commands/setup_command.rb
@@ -185,7 +185,7 @@ By default, this RubyGems will install g
 
     uninstall_old_gemcutter
 
-    documentation_success = install_rdoc
+    documentation_success = install_rdoc install_destdir
 
     say
     if @verbose
@@ -318,11 +318,15 @@ By default, this RubyGems will install g
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
@@ -333,7 +337,7 @@ By default, this RubyGems will install g
        (!File.exist?(rubygems_doc_dir) ||
         File.writable?(rubygems_doc_dir))
       say "Removing old RubyGems RDoc and ri" if @verbose
-      Dir[File.join(Gem.dir, "doc", "rubygems-[0-9]*")].each do |dir|
+      Dir[File.join(gem_doc_dir, "rubygems-[0-9]*")].each do |dir|
         rm_rf dir
       end
 
