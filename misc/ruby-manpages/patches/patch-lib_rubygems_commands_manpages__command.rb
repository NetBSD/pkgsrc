$NetBSD: patch-lib_rubygems_commands_manpages__command.rb,v 1.2 2026/05/31 06:01:00 taca Exp $

Fixate manpath.

--- lib/rubygems/commands/manpages_command.rb.orig	2026-05-24 01:59:08.966107032 +0000
+++ lib/rubygems/commands/manpages_command.rb
@@ -40,7 +40,7 @@ class Gem::Commands::ManpagesCommand < G
         Manpages::GemVersion.new(spec).latest?
 
       say "Installing man pages for #{spec.name} #{spec.version}"
-      target_dir = File.expand_path("#{Gem.bindir}/../share/man")
+      target_dir = File.expand_path("#{Gem.bindir}/../@PKGMANDIR@")
       Manpages::Install.new(spec, spec.gem_dir, target_dir).install_manpages
     end
   end
