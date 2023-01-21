$NetBSD: patch-lib_rubygems_config__file.rb,v 1.1 2023/01/21 13:51:23 taca Exp $

Avoid update suggestion default.

--- lib/rubygems/config_file.rb.orig	2022-12-25 06:55:25.000000000 +0000
+++ lib/rubygems/config_file.rb
@@ -201,6 +201,8 @@ class Gem::ConfigFile
       @hash = @hash.merge environment_config
     end
 
+    @hash['prevent_update_suggestion'] = true
+
     # HACK these override command-line args, which is bad
     @backtrace                   = @hash[:backtrace]                   if @hash.key? :backtrace
     @bulk_threshold              = @hash[:bulk_threshold]              if @hash.key? :bulk_threshold
