$NetBSD: patch-lib_rubygems_commands_build__command.rb,v 1.1 2019/02/03 13:41:33 taca Exp $

* Do not chdir to gemspec file's directory.

--- lib/rubygems/commands/build_command.rb.orig	2018-12-12 05:07:50.000000000 +0000
+++ lib/rubygems/commands/build_command.rb
@@ -60,20 +60,18 @@ Gems can be saved to a specified filenam
     end
 
     if File.exist? gemspec
-      Dir.chdir(File.dirname(gemspec)) do
-        spec = Gem::Specification.load File.basename(gemspec)
+      spec = Gem::Specification.load gemspec
 
-        if spec
-          Gem::Package.build(
-            spec,
-            options[:force],
-            options[:strict],
-            options[:output]
-          )
-        else
-          alert_error "Error loading gemspec. Aborting."
-          terminate_interaction 1
-        end
+      if spec
+        Gem::Package.build(
+          spec,
+          options[:force],
+          options[:strict],
+          options[:output]
+        )
+      else
+        alert_error "Error loading gemspec. Aborting."
+        terminate_interaction 1
       end
     else
       alert_error "Gemspec file not found: #{gemspec}"
