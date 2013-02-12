$NetBSD$

Fix for CVE-2013-0276.

--- lib/active_model/attribute_methods.rb.orig	2013-02-12 15:27:17.000000000 +0000
+++ lib/active_model/attribute_methods.rb
@@ -347,7 +347,7 @@ module ActiveModel
           def initialize(options = {})
             options.symbolize_keys!
             @prefix, @suffix = options[:prefix] || '', options[:suffix] || ''
-            @regex = /^(#{Regexp.escape(@prefix)})(.+?)(#{Regexp.escape(@suffix)})$/
+            @regex = /\A(#{Regexp.escape(@prefix)})(.+?)(#{Regexp.escape(@suffix)})\z/
           end
 
           def match(method_name)
