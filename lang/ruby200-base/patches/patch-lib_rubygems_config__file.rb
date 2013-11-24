$NetBSD: patch-lib_rubygems_config__file.rb,v 1.2 2013/11/24 14:22:03 taca Exp $

* Don't hard code config file's path for gem.

--- lib/rubygems/config_file.rb.orig	2013-10-24 14:31:17.000000000 +0000
+++ lib/rubygems/config_file.rb
@@ -57,32 +57,7 @@ class Gem::ConfigFile
 
   # :stopdoc:
 
-  system_config_path =
-    begin
-      require "etc"
-      Etc.sysconfdir
-    rescue LoadError, NoMethodError
-      begin
-        # TODO: remove after we drop 1.8.7 and 1.9.1
-        require 'Win32API'
-
-        CSIDL_COMMON_APPDATA = 0x0023
-        path = 0.chr * 260
-        if RUBY_VERSION > '1.9' then
-          SHGetFolderPath = Win32API.new 'shell32', 'SHGetFolderPath', 'PLPLP',
-          'L', :stdcall
-          SHGetFolderPath.call nil, CSIDL_COMMON_APPDATA, nil, 1, path
-        else
-          SHGetFolderPath = Win32API.new 'shell32', 'SHGetFolderPath', 'LLLLP',
-          'L'
-          SHGetFolderPath.call 0, CSIDL_COMMON_APPDATA, 0, 1, path
-        end
-
-        path.strip
-      rescue LoadError
-        RbConfig::CONFIG["sysconfdir"] || "/etc"
-      end
-    end
+  system_config_path = '@PKG_SYSCONFDIR@'
 
   # :startdoc:
 
