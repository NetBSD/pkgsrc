$NetBSD: patch-lib_rubygems_commands_uninstall__command.rb,v 1.1 2014/03/14 19:40:47 taca Exp $

* Add install_root option for pkgsrc's rubygems support.

--- lib/rubygems/commands/uninstall_command.rb.orig	2013-09-18 21:29:41.000000000 +0000
+++ lib/rubygems/commands/uninstall_command.rb
@@ -23,6 +23,11 @@ class Gem::Commands::UninstallCommand < 
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
