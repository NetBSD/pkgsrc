$NetBSD: patch-lib_rubygems_config__file.rb,v 1.1 2024/01/21 08:22:03 taca Exp $

Avoid update suggestion default.

--- lib/rubygems/config_file.rb.orig	2023-12-11 07:06:03.000000000 +0000
+++ lib/rubygems/config_file.rb
@@ -202,6 +202,8 @@ class Gem::ConfigFile
       @hash = @hash.merge environment_config
     end
 
+    @hash['prevent_update_suggestion'] = true
+
     # HACK: these override command-line args, which is bad
     @backtrace                   = @hash[:backtrace]                   if @hash.key? :backtrace
     @bulk_threshold              = @hash[:bulk_threshold]              if @hash.key? :bulk_threshold
