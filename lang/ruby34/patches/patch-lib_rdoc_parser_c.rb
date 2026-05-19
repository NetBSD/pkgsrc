$NetBSD: patch-lib_rdoc_parser_c.rb,v 1.1 2026/05/19 14:50:20 taca Exp $

Backport from rdoc-7.0.4.

--- lib/rdoc/parser/c.rb.orig	2026-03-11 09:51:47.000000000 +0000
+++ lib/rdoc/parser/c.rb
@@ -1023,7 +1023,7 @@ class RDoc::Parser::C < RDoc::Parser
         file_name = File.join @file_dir, source_file
 
         if File.exist? file_name then
-          file_content = File.read file_name
+          file_content = RDoc::Encoding.read_file file_name, @options.encoding
         else
           @options.warn "unknown source #{source_file} for #{meth_name} in #{@file_name}"
         end
