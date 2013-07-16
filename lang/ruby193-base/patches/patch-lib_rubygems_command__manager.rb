$NetBSD: patch-lib_rubygems_command__manager.rb,v 1.1.2.2 2013/07/16 17:00:50 tron Exp $

* Support partly build_args options.

--- lib/rubygems/command_manager.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/command_manager.rb
@@ -113,8 +113,8 @@ class Gem::CommandManager
   ##
   # Run the config specified by +args+.
 
-  def run(args)
-    process_args(args)
+  def run(args, build_args=nil)
+    process_args(args, build_args)
   rescue StandardError, Timeout::Error => ex
     alert_error "While executing gem ... (#{ex.class})\n    #{ex.to_s}"
     ui.errs.puts "\t#{ex.backtrace.join "\n\t"}" if
@@ -125,13 +125,15 @@ class Gem::CommandManager
     terminate_interaction(1)
   end
 
-  def process_args(args)
+  def process_args(args, build_args=nil)
     args = args.to_str.split(/\s+/) if args.respond_to?(:to_str)
-    if args.size == 0
+
+    if args.empty? then
       say Gem::Command::HELP
-      terminate_interaction(1)
+      terminate_interaction 1
     end
-    case args[0]
+
+    case args.first
     when '-h', '--help'
       say Gem::Command::HELP
       terminate_interaction(0)
@@ -144,7 +146,7 @@ class Gem::CommandManager
     else
       cmd_name = args.shift.downcase
       cmd = find_command(cmd_name)
-      cmd.invoke(*args)
+      cmd.invoke_with_build_args args, build_args
     end
   end
 
