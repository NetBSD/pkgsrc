$NetBSD: patch-lib_rdoc_options.rb,v 1.1 2011/03/28 14:10:25 taca Exp $

* Ignore none existing files as newer version of rdoc.

--- lib/rdoc/options.rb.orig	2008-01-11 01:24:05.000000000 +0000
+++ lib/rdoc/options.rb
@@ -573,7 +573,7 @@ class Options
   
   def check_files
     @files.each do |f|
-      stat = File.stat f rescue error("File not found: #{f}")
+      stat = File.stat f rescue next
       error("File '#{f}' not readable") unless stat.readable?
     end
   end
