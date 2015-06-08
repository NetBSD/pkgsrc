$NetBSD: patch-setup.rb,v 1.1 2015/06/08 14:55:17 taca Exp $

Fix build problem on Ruby 2.2 and later.

--- setup.rb.orig	2004-10-30 14:17:39.000000000 +0000
+++ setup.rb
@@ -256,7 +256,7 @@ class ConfigTable_class
 
 end
 
-c = ::Config::CONFIG
+c = ::RbConfig::CONFIG
 
 rubypath = c['bindir'] + '/' + c['ruby_install_name']
 
@@ -1246,7 +1246,7 @@ class Installer
 
   def ruby_extentions(dir)
     Dir.open(dir) {|d|
-      ents = d.select {|fname| /\.#{::Config::CONFIG['DLEXT']}\z/ =~ fname }
+      ents = d.select {|fname| /\.#{::RbConfig::CONFIG['DLEXT']}\z/ =~ fname }
       if ents.empty?
         setup_rb_error "no ruby extention exists: 'ruby #{$0} setup' first"
       end
