$NetBSD: patch-lib_rdoc_encoding.rb,v 1.1 2022/01/16 13:57:10 taca Exp $

* Always convert "\r\n" to "\n" since it cause rdoc processing error.

--- lib/rdoc/encoding.rb.orig	2018-03-26 05:56:26.000000000 +0000
+++ lib/rdoc/encoding.rb
@@ -31,7 +31,7 @@ module RDoc::Encoding
 
   def self.read_file filename, encoding, force_transcode = false
     content = File.open filename, "rb" do |f| f.read end
-    content.gsub!("\r\n", "\n") if RUBY_PLATFORM =~ /mswin|mingw/
+    content.gsub!("\r\n", "\n")
 
     utf8 = content.sub!(/\A\xef\xbb\xbf/, '')
 
