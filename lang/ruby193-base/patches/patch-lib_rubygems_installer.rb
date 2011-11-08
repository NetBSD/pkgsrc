$NetBSD: patch-lib_rubygems_installer.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/installer.rb.orig	2011-08-04 22:39:35.000000000 +0000
+++ lib/rubygems/installer.rb
@@ -85,6 +85,9 @@ class Gem::Installer
   #          for a signed-gems-only policy.
   # :ignore_dependencies:: Don't raise if a dependency is missing.
   # :install_dir:: The directory to install the gem into.
+  # :install_root:: The directory to use as a buildroot for "destdir"-style
+  #		  installation.  All paths during installation are relative
+  #               to the buildroot.
   # :format_executable:: Format the executable the same as the ruby executable.
   #                      If your ruby is ruby18, foo_exec will be installed as
   #                      foo_exec18.
@@ -283,7 +286,11 @@ class Gem::Installer
     # If the user has asked for the gem to be installed in a directory that is
     # the system gem directory, then use the system bin directory, else create
     # (or use) a new bin dir under the gem_home.
-    bindir = @bin_dir || Gem.bindir(gem_home)
+    bindir = @bin_dir ? @bin_dir : (Gem.bindir @gem_home, @install_root)
+
+    unless @install_root.nil? or @install_root == ""
+      bindir = File.join(@install_root, bindir)
+    end
 
     Dir.mkdir bindir unless File.exist? bindir
     raise Gem::FilePermissionError.new(bindir) unless File.writable? bindir
@@ -416,6 +423,7 @@ class Gem::Installer
       :exec_format  => false,
       :force        => false,
       :install_dir  => Gem.dir,
+      :install_root => nil,
     }.merge options
 
     @env_shebang         = options[:env_shebang]
@@ -425,6 +433,11 @@ class Gem::Installer
     @format_executable   = options[:format_executable]
     @security_policy     = options[:security_policy]
     @wrappers            = options[:wrappers]
+    install_root         = options[:install_root]
+    unless install_root.nil? or install_root == ""
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
     @bin_dir             = options[:bin_dir]
     @development         = options[:development]
 
