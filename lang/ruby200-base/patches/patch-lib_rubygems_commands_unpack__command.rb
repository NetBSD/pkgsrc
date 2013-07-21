$NetBSD: patch-lib_rubygems_commands_unpack__command.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/commands/unpack_command.rb.orig	2012-11-29 06:52:18.000000000 +0000
+++ lib/rubygems/commands/unpack_command.rb
@@ -14,6 +14,10 @@ class Gem::Commands::UnpackCommand < Gem
           :version => Gem::Requirement.default,
           :target  => Dir.pwd
 
+    add_option('--install-root DIR', 'Root directory for gem files on extract') do |value, options|
+      options[:install_root] = value
+    end
+
     add_option('--target=DIR',
                'target directory for unpacking') do |value, options|
       options[:target] = value
@@ -69,6 +73,9 @@ class Gem::Commands::UnpackCommand < Gem
       else
         basename = File.basename path, '.gem'
         target_dir = File.expand_path basename, options[:target]
+        if options[:install_root]
+          target_dir = File.join(options[:install_root], target_dir)
+        end
 
         package = Gem::Package.new path
         package.extract_files target_dir
