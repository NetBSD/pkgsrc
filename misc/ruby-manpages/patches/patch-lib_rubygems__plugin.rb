$NetBSD: patch-lib_rubygems__plugin.rb,v 1.1.2.1 2023/01/08 15:57:24 bsiegert Exp $

* Fixate manpath.
* Handle --install-root option.

--- lib/rubygems_plugin.rb.orig	2022-12-29 16:12:22.401050134 +0000
+++ lib/rubygems_plugin.rb
@@ -6,15 +6,18 @@ Gem::CommandManager.instance.register_co
 
 Gem.post_install do |installer|
   source_dir = installer.spec.gem_dir
-  target_dir = File.expand_path("#{installer.bin_dir}/../share/man")
-
-  Manpages::Install.new(installer.spec, source_dir, target_dir).install_manpages
+  target_dir = File.expand_path("#{installer.bin_dir}/../@PKGMANDIR@")
+  install_root = nil
+  if installer.options[:install_root]
+    install_root = installer.options[:install_root]
+  end
+  Manpages::Install.new(installer.spec, source_dir, target_dir, install_root).install_manpages
 end
 
 Gem.pre_uninstall do |uninstaller|
   bin_dir = uninstaller.bin_dir || Gem.bindir(uninstaller.spec.base_dir)
   source_dir = uninstaller.spec.gem_dir
-  target_dir = File.expand_path("#{bin_dir}/../share/man")
+  target_dir = File.expand_path("#{bin_dir}/../@PKGMANDIR@")
 
   Manpages::Uninstall.new(uninstaller.spec, source_dir, target_dir).uninstall_manpages
 end
