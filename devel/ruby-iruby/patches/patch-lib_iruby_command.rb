$NetBSD: patch-lib_iruby_command.rb,v 1.2 2021/05/29 15:04:32 taca Exp $

* For versioned ipython command from pkgsrc.

--- lib/iruby/command.rb.orig	2021-05-29 02:19:05.405882756 +0000
+++ lib/iruby/command.rb
@@ -111,7 +111,7 @@ Try `ipython help` for more information.
 
     def check_version
       required = '3.0.0'
-      version = `ipython --version`.chomp
+      version = `ipython-@PYVERSSUFFIX@ --version`.chomp
       if version < required
         STDERR.puts "Your IPython version #{version} is too old, at least #{required} is required"
         exit 1
@@ -127,7 +127,7 @@ Try `ipython help` for more information.
       check_registered_kernel
       check_bundler {|e| STDERR.puts "Could not load bundler: #{e.message}" }
 
-      Process.exec('ipython', *@args)
+      Process.exec('ipython-@PYVERSSUFFIX@', *@args)
     end
 
     def check_registered_kernel
