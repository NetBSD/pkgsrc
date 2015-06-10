$NetBSD: patch-setup.rb,v 1.1 2015/06/10 14:47:59 taca Exp $

Do not use obsolete Config.

--- setup.rb.orig	2012-11-24 17:54:50.000000000 +0000
+++ setup.rb
@@ -102,7 +102,7 @@ end
 
 class ConfigTable
 
-  c = ::Config::CONFIG
+  c = ::RbConfig::CONFIG
 
   rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -1219,7 +1219,7 @@ class Installer
         raise InstallError, "no ruby extention exists: 'ruby #{$0} setup' first"
   end
 
-  DLEXT = /\.#{ ::Config::CONFIG['DLEXT'] }\z/
+  DLEXT = /\.#{ ::RbConfig::CONFIG['DLEXT'] }\z/
 
   def _ruby_extentions(dir)
     Dir.open(dir) {|d|
