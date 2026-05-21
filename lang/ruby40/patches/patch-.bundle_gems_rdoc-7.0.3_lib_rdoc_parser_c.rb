$NetBSD: patch-.bundle_gems_rdoc-7.0.3_lib_rdoc_parser_c.rb,v 1.2.2.2 2026/05/21 03:07:30 maya Exp $

Backport from rdoc-7.0.4.

--- .bundle/gems/rdoc-7.0.3/lib/rdoc/parser/c.rb.orig	2026-05-11 21:07:54.000000000 +0000
+++ .bundle/gems/rdoc-7.0.3/lib/rdoc/parser/c.rb
@@ -1014,7 +1014,7 @@ class RDoc::Parser::C < RDoc::Parser
         file_name = File.join @file_dir, source_file
 
         if File.exist? file_name then
-          file_content = File.read file_name
+          file_content = RDoc::Encoding.read_file file_name, @options.encoding
         else
           @options.warn "unknown source #{source_file} for #{meth_name} in #{@file_name}"
         end
