$NetBSD: patch-lib_rubygems_dependency__installer.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/dependency_installer.rb.orig	2022-12-25 06:55:25.000000000 +0000
+++ lib/rubygems/dependency_installer.rb
@@ -22,6 +22,7 @@ class Gem::DependencyInstaller
     :force => false,
     :format_executable => false, # HACK dup
     :ignore_dependencies => false,
+      :install_root => @install_root,
     :prerelease => false,
     :security_policy => nil, # HACK NoSecurity requires OpenSSL. AlmostNo? Low?
     :wrappers => true,
@@ -58,6 +59,7 @@ class Gem::DependencyInstaller
   # :format_executable:: See Gem::Installer#initialize.
   # :ignore_dependencies:: Don't install any dependencies.
   # :install_dir:: See Gem::Installer#install.
+  # :install_root:: See Gem::Installer#install.
   # :prerelease:: Allow prerelease versions.  See #install.
   # :security_policy:: See Gem::Installer::new and Gem::Security.
   # :user_install:: See Gem::Installer.new
@@ -99,7 +101,12 @@ class Gem::DependencyInstaller
     @installed_gems = []
     @toplevel_specs = nil
 
-    @cache_dir = options[:cache_dir] || @install_dir
+    @install_root = options[:install_root] || ""
+    install_dir = @install_dir
+    unless @install_root.nil? or @install_root.empty?
+      install_dir = File.join(@install_root, install_dir)
+    end
+    @cache_dir = options[:cache_dir] || install_dir
 
     @errors = []
   end
