$NetBSD: patch-.bundle_gems_rdoc-7.0.4_lib_rdoc_encoding.rb,v 1.1 2026/05/20 13:13:37 taca Exp $

* Always convert "\r\n" to "\n" since it cause rdoc processing error.

--- .bundle/gems/rdoc-7.0.4/lib/rdoc/encoding.rb.orig	2026-05-19 23:22:56.000000000 +0000
+++ .bundle/gems/rdoc-7.0.4/lib/rdoc/encoding.rb
@@ -31,7 +31,7 @@ module RDoc::Encoding
 
   def self.read_file(filename, encoding, force_transcode = false)
     content = File.open filename, "rb" do |f| f.read end
-    content.gsub!("\r\n", "\n") if RUBY_PLATFORM =~ /mswin|mingw/
+    content.gsub!("\r\n", "\n")
 
     utf8 = content.sub!(/\A\xef\xbb\xbf/, '')
 
