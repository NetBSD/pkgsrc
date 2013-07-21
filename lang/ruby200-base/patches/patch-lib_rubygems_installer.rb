$NetBSD: patch-lib_rubygems_installer.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Add install_root option for pkgsrc's rubygems support.
* Tweak build_info directory with destdir to store build_args.

--- lib/rubygems/installer.rb.orig	2013-03-17 14:51:53.000000000 +0000
+++ lib/rubygems/installer.rb
@@ -89,6 +89,9 @@ class Gem::Installer
   #                      foo_exec18.
   # :ignore_dependencies:: Don't raise if a dependency is missing.
   # :install_dir:: The directory to install the gem into.
+  # :install_root:: The directory to use as a buildroot for "destdir"-style
+  #		  installation.  All paths during installation are relative
+  #               to the buildroot.
   # :security_policy:: Use the specified security policy.  See Gem::Security
   # :user_install:: Indicate that the gem should be unpacked into the users
   #                 personal gem directory.
@@ -548,12 +551,20 @@ class Gem::Installer
     @format_executable   = options[:format_executable]
     @security_policy     = options[:security_policy]
     @wrappers            = options[:wrappers]
+    install_root         = options[:install_root]
+    unless install_root.nil? or install_root == ""
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
     @only_install_dir    = options[:only_install_dir]
 
     # If the user has asked for the gem to be installed in a directory that is
     # the system gem directory, then use the system bin directory, else create
     # (or use) a new bin dir under the gem_home.
-    @bin_dir             = options[:bin_dir] || Gem.bindir(gem_home)
+    @bin_dir             = options[:bin_dir] || Gem.bindir(gem_home, @install_root)
+    if not @install_root.empty?
+      @bin_dir = File.join(@install_root, @bin_dir)
+    end
     @development         = options[:development]
 
     @build_args          = options[:build_args] || Gem::Command.build_args
@@ -773,7 +784,11 @@ EOF
   def write_build_info_file
     return if @build_args.empty?
 
-    open spec.build_info_file, 'w' do |io|
+    build_info_file = spec.build_info_file
+    unless @install_root.nil?
+      build_info_file = File.join @gem_home, "build_info", "#{spec.full_name}.info"
+    end
+    open build_info_file, 'w' do |io|
       @build_args.each do |arg|
         io.puts arg
       end
