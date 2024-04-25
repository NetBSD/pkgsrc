$NetBSD: patch-lib_rubygems_config__file.rb,v 1.2 2024/04/25 15:12:05 taca Exp $

Avoid update suggestion default.

--- lib/rubygems/config_file.rb.orig	2024-04-23 10:20:14.000000000 +0000
+++ lib/rubygems/config_file.rb
@@ -213,6 +213,8 @@ class Gem::ConfigFile
       end
     end
 
+    @hash['prevent_update_suggestion'] = true
+
     # HACK: these override command-line args, which is bad
     @backtrace                   = @hash[:backtrace]                   if @hash.key? :backtrace
     @bulk_threshold              = @hash[:bulk_threshold]              if @hash.key? :bulk_threshold
