$NetBSD: patch-lib_rubygems_commands_uninstall__command.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/commands/uninstall_command.rb.orig	2012-12-06 05:26:46.000000000 +0000
+++ lib/rubygems/commands/uninstall_command.rb
@@ -22,6 +22,11 @@ class Gem::Commands::UninstallCommand < 
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
