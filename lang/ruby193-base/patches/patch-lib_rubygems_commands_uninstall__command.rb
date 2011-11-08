$NetBSD: patch-lib_rubygems_commands_uninstall__command.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/commands/uninstall_command.rb.orig	2011-08-26 01:12:57.000000000 +0000
+++ lib/rubygems/commands/uninstall_command.rb
@@ -21,6 +21,11 @@ class Gem::Commands::UninstallCommand < 
       options[:all] = value
     end
 
+    add_option('-B', '--install-root DIR',
+               'Root directory for gem files') do |value, options|
+      options[:install_root] = File.expand_path(value)
+    end
+
     add_option('-I', '--[no-]ignore-dependencies',
                'Ignore dependency requirements while',
                'uninstalling') do |value, options|
