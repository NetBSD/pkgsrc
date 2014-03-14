$NetBSD: patch-lib_rubygems_installer.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Add install_root option for pkgsrc's rubygems support.
* Tweak build_info directory with destdir to store build_args.

--- lib/rubygems/installer.rb.orig	2013-12-19 03:05:37.000000000 +0000
+++ lib/rubygems/installer.rb
@@ -95,6 +95,9 @@ class Gem::Installer
   #                      foo_exec18.
   # :ignore_dependencies:: Don't raise if a dependency is missing.
   # :install_dir:: The directory to install the gem into.
+  # :install_root:: The directory to use as a buildroot for "destdir"-style
+  #		  installation.  All paths during installation are relative
+  #               to the buildroot.
   # :security_policy:: Use the specified security policy.  See Gem::Security
   # :user_install:: Indicate that the gem should be unpacked into the users
   #                 personal gem directory.
@@ -583,12 +586,20 @@ class Gem::Installer
     @format_executable   = options[:format_executable]
     @security_policy     = options[:security_policy]
     @wrappers            = options[:wrappers]
+    install_root         = options[:install_root]
+    unless install_root.nil? or install_root.empty?
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
     @only_install_dir    = options[:only_install_dir]
 
     # If the user has asked for the gem to be installed in a directory that is
     # the system gem directory, then use the system bin directory, else create
     # (or use) a new bin dir under the gem_home.
-    @bin_dir             = options[:bin_dir] || Gem.bindir(gem_home)
+    @bin_dir             = options[:bin_dir] || Gem.bindir(gem_home, @install_root)
+    unless @install_root.nil? or @install_root.empty?
+      @bin_dir = File.join(@install_root, @bin_dir)
+    end
     @development         = options[:development]
 
     @build_args          = options[:build_args] || Gem::Command.build_args
@@ -769,6 +780,9 @@ TEXT
     return if @build_args.empty?
 
     build_info_dir = File.join gem_home, 'build_info'
+    unless @install_root.nil? or @install_root.empty?
+      build_info_dir = File.join @gem_home, "build_info"
+    end
 
     FileUtils.mkdir_p build_info_dir
 
