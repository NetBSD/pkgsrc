$NetBSD: patch-lib_rdoc_rdoc.rb,v 1.1 2011/03/28 14:10:25 taca Exp $

* Ignore none existing files as newer version of rdoc.

--- lib/rdoc/rdoc.rb.orig	2007-02-12 23:01:19.000000000 +0000
+++ lib/rdoc/rdoc.rb
@@ -174,7 +174,7 @@ module RDoc
 
       relative_files.each do |rel_file_name|
         next if exclude_pattern && exclude_pattern =~ rel_file_name
-        stat = File.stat(rel_file_name)
+        stat = File.stat(rel_file_name) rescue next
         case type = stat.ftype
         when "file"
           next if @last_created and stat.mtime < @last_created
