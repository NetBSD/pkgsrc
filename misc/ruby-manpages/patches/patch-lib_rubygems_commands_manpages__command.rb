$NetBSD: patch-lib_rubygems_commands_manpages__command.rb,v 1.1 2022/11/11 14:06:24 taca Exp $

Fixate manpath.

--- lib/rubygems/commands/manpages_command.rb.orig	2022-11-08 15:03:34.184546225 +0000
+++ lib/rubygems/commands/manpages_command.rb
@@ -38,7 +38,7 @@ class Gem::Commands::ManpagesCommand < G
           Manpages::GemVersion.new(spec).latest?
 
       say "Installing man pages for #{spec.name} #{spec.version}"
-      target_dir = File.expand_path("#{Gem.bindir}/../share/man")
+      target_dir = File.expand_path("#{Gem.bindir}/../@PKGMANDIR@")
       Manpages::Install.new(spec, spec.gem_dir, target_dir).install_manpages
     end
   end
