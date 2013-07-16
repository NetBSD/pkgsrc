$NetBSD: patch-lib_rubygems_gem__runner.rb,v 1.1.2.2 2013/07/16 17:00:50 tron Exp $

* Support partly build_args options.

--- lib/rubygems/gem_runner.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/gem_runner.rb
@@ -62,7 +60,7 @@ class Gem::GemRunner
       Gem::Command.add_specific_extra_args command_name, config_args
     end
 
-    cmd.run Gem.configuration.args
+    cmd.run Gem.configuration.args, build_args
     end_time = Time.now
 
     if Gem.configuration.benchmark then
