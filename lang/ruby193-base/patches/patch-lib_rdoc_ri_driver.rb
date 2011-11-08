$NetBSD: patch-lib_rdoc_ri_driver.rb,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Defer loading readline, when it is really needed.
Some unknown reason:

1. build devel/ruby-readline with editline(3).
2. Execute a ruby script loading readline in background from shell.
3. When the script output something to stdout, it got SIGTSTP and suspends.

There is no such problem when build devel/ruby-readline with GNU's readline.

--- lib/rdoc/ri/driver.rb.orig	2011-08-05 21:21:55.000000000 +0000
+++ lib/rdoc/ri/driver.rb
@@ -2,11 +2,6 @@ require 'abbrev'
 require 'optparse'
 
 begin
-  require 'readline'
-rescue LoadError
-end
-
-begin
   require 'win32console'
 rescue LoadError
 end
@@ -858,6 +853,11 @@ Options may also be set in the 'RI' envi
   # Runs ri interactively using Readline if it is available.
 
   def interactive
+    begin
+      require 'readline'
+    rescue LoadError
+    end
+
     puts "\nEnter the method name you want to look up."
 
     if defined? Readline then
