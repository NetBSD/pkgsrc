$NetBSD: patch-lib_rubygems_installer.rb,v 1.3 2014/02/19 15:50:53 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/installer.rb.orig	2012-10-25 09:18:59.000000000 +0000
+++ lib/rubygems/installer.rb
@@ -85,11 +85,16 @@ class Gem::Installer
   #          for a signed-gems-only policy.
   # :ignore_dependencies:: Don't raise if a dependency is missing.
   # :install_dir:: The directory to install the gem into.
+  # :install_root:: The directory to use as a buildroot for "destdir"-style
+  #		  installation.  All paths during installation are relative
+  #               to the buildroot.
   # :format_executable:: Format the executable the same as the ruby executable.
   #                      If your ruby is ruby18, foo_exec will be installed as
   #                      foo_exec18.
   # :security_policy:: Use the specified security policy.  See Gem::Security
   # :wrappers:: Install wrappers if true, symlinks if false.
+  # :build_args:: An Array of arguments to pass to the extension builder
+  #               process. If not set, then Gem::Command.build_args is used
 
   def initialize(gem, options={})
     require 'fileutils'
@@ -178,6 +183,7 @@ class Gem::Installer
 
     extract_files
     build_extensions
+    write_build_info_file
 
     Gem.post_build_hooks.each do |hook|
       result = hook.call self
@@ -283,7 +289,11 @@ class Gem::Installer
     # If the user has asked for the gem to be installed in a directory that is
     # the system gem directory, then use the system bin directory, else create
     # (or use) a new bin dir under the gem_home.
-    bindir = @bin_dir || Gem.bindir(gem_home)
+    bindir = @bin_dir ? @bin_dir : (Gem.bindir @gem_home, @install_root)
+
+    unless @install_root.nil? or @install_root.empty?
+      bindir = File.join(@install_root, bindir)
+    end
 
     Dir.mkdir bindir unless File.exist? bindir
     raise Gem::FilePermissionError.new(bindir) unless File.writable? bindir
@@ -416,6 +426,7 @@ class Gem::Installer
       :exec_format  => false,
       :force        => false,
       :install_dir  => Gem.dir,
+      :install_root => nil,
     }.merge options
 
     @env_shebang         = options[:env_shebang]
@@ -425,9 +436,16 @@ class Gem::Installer
     @format_executable   = options[:format_executable]
     @security_policy     = options[:security_policy]
     @wrappers            = options[:wrappers]
+    install_root         = options[:install_root]
+    unless install_root.nil? or install_root.empty?
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+    end
     @bin_dir             = options[:bin_dir]
     @development         = options[:development]
 
+    @build_args          = options[:build_args] || Gem::Command.build_args
+
     raise "NOTE: Installer option :source_index is dead" if
       options[:source_index]
   end
@@ -622,5 +640,23 @@ EOF
   def dir
     gem_dir.to_s
   end
+
+  ##
+  # Writes the file containing the arguments for building this gem's
+  # extensions.
+
+  def write_build_info_file
+    return if @build_args.empty?
+
+    build_info_file = spec.build_info_file
+    build_info_dir = File.dirname build_info_file
+    FileUtils.mkdir_p build_info_dir
+    open build_info_file, 'w' do |io|
+      @build_args.each do |arg|
+        io.puts arg
+      end
+    end
+  end
+
 end
 
