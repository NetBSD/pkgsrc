$NetBSD: patch-lib_rubygems_commands_unpack__command.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/commands/unpack_command.rb.orig	2013-09-25 00:53:19.000000000 +0000
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
@@ -87,6 +91,9 @@ command help for an example.
       else
         basename = File.basename path, '.gem'
         target_dir = File.expand_path basename, options[:target]
+        if options[:install_root]
+          target_dir = File.join(options[:install_root], target_dir)
+        end
 
         package = Gem::Package.new path
         package.extract_files target_dir
