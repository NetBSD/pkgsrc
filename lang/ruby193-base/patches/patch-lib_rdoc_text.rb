$NetBSD: patch-lib_rdoc_text.rb,v 1.1 2015/03/08 14:53:39 taca Exp $

* Get rid of infitite loop with '\r' only in text.

--- lib/rdoc/text.rb.orig	2011-08-05 21:21:55.000000000 +0000
+++ lib/rdoc/text.rb
@@ -45,11 +45,11 @@ module RDoc::Text
     expanded = []
 
     text.each_line do |line|
-      line.gsub!(/^(.{8}*?)([^\t\r\n]{0,7})\t/) do
+      nil while line.gsub!(/(?:\G|\r)((?:.{8})*?)([^\t\r\n]{0,7})\t/) do
         r = "#{$1}#{$2}#{' ' * (8 - $2.size)}"
         r.force_encoding text.encoding if Object.const_defined? :Encoding
         r
-      end until line !~ /\t/
+      end
 
       expanded << line
     end
