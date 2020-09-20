$NetBSD: patch-lib_iruby_command.rb,v 1.1 2020/09/20 08:57:32 ryoon Exp $

* For versioned ipython command from pkgsrc.

--- lib/iruby/command.rb.orig	2020-09-18 09:20:04.795404140 +0000
+++ lib/iruby/command.rb
@@ -115,7 +115,7 @@ Try `ipython help` for more information.
 
     def check_version
       required = '3.0.0'
-      version = `ipython --version`.chomp
+      version = `ipython-@PYVERSSUFFIX@ --version`.chomp
       if version < required
         STDERR.puts "Your IPython version #{version} is too old, at least #{required} is required"
         exit 1
@@ -131,7 +131,7 @@ Try `ipython help` for more information.
       check_registered_kernel
       check_bundler {|e| STDERR.puts "Could not load bundler: #{e.message}" }
 
-      Kernel.exec('ipython', *@args)
+      Kernel.exec('ipython-@PYVERSSUFFIX@', *@args)
     end
 
     def check_registered_kernel
