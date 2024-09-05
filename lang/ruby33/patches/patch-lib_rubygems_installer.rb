$NetBSD: patch-lib_rubygems_installer.rb,v 1.2 2024/09/05 15:02:42 taca Exp $

* Add install_root option for pkgsrc's rubygems support.
* Tweak build_info directory with destdir to store build_args.
* Fix from "Installer lock file cleanup #7939".

--- lib/rubygems/installer.rb.orig	2024-09-03 01:09:08.000000000 +0900
+++ lib/rubygems/installer.rb	2024-09-05 23:34:15.179174905 +0900
@@ -167,6 +167,9 @@ class Gem::Installer
   #                      foo_exec18.
   # :ignore_dependencies:: Don't raise if a dependency is missing.
   # :install_dir:: The directory to install the gem into.
+  # :install_root:: The directory to use as a buildroot for "destdir"-style
+  #		  installation.  All paths during installation are relative
+  #               to the buildroot.
   # :security_policy:: Use the specified security policy.  See Gem::Security
   # :user_install:: Indicate that the gem should be unpacked into the users
   #                 personal gem directory.
@@ -538,7 +541,7 @@
   def generate_bin_script(filename, bindir)
     bin_script_path = File.join bindir, formatted_program_filename(filename)
 
-    Gem.open_file_with_flock("#{bin_script_path}.lock") do
+    Gem.open_file_with_flock("#{bin_script_path}.lock") do |lock|
       require "fileutils"
       FileUtils.rm_f bin_script_path # prior install may have been --no-wrappers
 
@@ -546,6 +549,8 @@
         file.write app_script_text(filename)
         file.chmod(options[:prog_mode] || 0o755)
       end
+    ensure
+      FileUtils.rm_f lock.path
     end
 
     verbose bin_script_path
@@ -676,12 +679,20 @@ class Gem::Installer
 
     @build_args = options[:build_args]
 
+    install_root         = options[:install_root]
+
     @gem_home = @install_dir || user_install_dir || Gem.dir
 
     # If the user has asked for the gem to be installed in a directory that is
     # the system gem directory, then use the system bin directory, else create
     # (or use) a new bin dir under the gem_home.
-    @bin_dir ||= Gem.bindir(@gem_home)
+    @bin_dir ||= Gem.bindir(@gem_home, install_root)
+
+    unless install_root.nil? or install_root.empty?
+      @install_root = File.expand_path install_root
+      @gem_home = File.join(@install_root, @gem_home)
+      @plugins_dir         = Gem.plugindir(@gem_home)
+    end
 
     @plugins_dir = Gem.plugindir(@gem_home)
 
@@ -937,6 +948,9 @@ TEXT
     return if build_args.empty?
 
     build_info_dir = File.join gem_home, "build_info"
+    unless @install_root.nil? or @install_root.empty?
+      build_info_dir = File.join @gem_home, "build_info"
+    end
 
     dir_mode = options[:dir_mode]
     FileUtils.mkdir_p build_info_dir, mode: dir_mode && 0o755
