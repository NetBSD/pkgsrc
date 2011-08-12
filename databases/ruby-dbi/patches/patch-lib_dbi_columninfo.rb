$NetBSD: patch-lib_dbi_columninfo.rb,v 1.1 2011/08/12 15:58:36 taca Exp $

* Create array of hash's key since hash would be modified in the block.

--- lib/dbi/columninfo.rb.orig	2011-08-09 05:56:50.000000000 +0000
+++ lib/dbi/columninfo.rb
@@ -39,7 +39,7 @@ module DBI
             @hash ||= Hash.new
 
             # coerce all strings to symbols
-            @hash.each_key do |x|
+            @hash.keys.each do |x|
                 if x.kind_of? String
                     sym = x.to_sym
                     if @hash.has_key? sym
