$NetBSD: patch-lib_rubygems_command.rb,v 1.1.2.2 2013/07/16 17:00:50 tron Exp $

* Support partly build_args options.

--- lib/rubygems/command.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/command.rb
@@ -268,8 +268,18 @@ class Gem::Command
   # Invoke the command with the given list of arguments.
 
   def invoke(*args)
+    invoke_with_build_args args, nil
+  end
+
+  ##
+  # Invoke the command with the given list of normal arguments
+  # and additional build arguments.
+
+  def invoke_with_build_args(args, build_args)
     handle_options args
 
+    options[:build_args] = build_args
+
     if options[:help] then
       show_help
     elsif @when_invoked then
@@ -344,7 +354,7 @@ class Gem::Command
 
   def handle_options(args)
     args = add_extra_args(args)
-    @options = @defaults.clone
+    @options = Marshal.load Marshal.dump @defaults # deep copy
     parser.parse!(args)
     @options[:args] = args
   end
