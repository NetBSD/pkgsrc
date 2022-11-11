$NetBSD: patch-lib_rubygems__plugin.rb,v 1.1 2022/11/11 14:06:24 taca Exp $

Fixate manpath.

--- lib/rubygems_plugin.rb.orig	2022-11-08 15:03:34.185367972 +0000
+++ lib/rubygems_plugin.rb
@@ -6,7 +6,7 @@ Gem::CommandManager.instance.register_co
 
 Gem.post_install do |installer|
   source_dir = installer.spec.gem_dir
-  target_dir = File.expand_path("#{installer.bin_dir}/../share/man")
+  target_dir = File.expand_path("#{installer.bin_dir}/../@PKGMANDIR@")
 
   Manpages::Install.new(installer.spec, source_dir, target_dir).install_manpages
 end
@@ -14,7 +14,7 @@ end
 Gem.pre_uninstall do |uninstaller|
   bin_dir = uninstaller.bin_dir || Gem.bindir(uninstaller.spec.base_dir)
   source_dir = uninstaller.spec.gem_dir
-  target_dir = File.expand_path("#{bin_dir}/../share/man")
+  target_dir = File.expand_path("#{bin_dir}/../@PKGMANDIR@")
 
   Manpages::Uninstall.new(uninstaller.spec, source_dir, target_dir).uninstall_manpages
 end
