$NetBSD: patch-lib__rb__setup.rb,v 1.1.40.1 2016/06/11 18:31:02 spz Exp $

* Changes for pkgsrc.
* Remove duplicate 'bin-dir' key.
* Do not use obsolete Config::CONFIG but RbConfig::CONFIG.

pkgsrc prefers vendor Ruby dirs.
--- lib/rb/setup.rb.orig	2011-08-11 13:19:12.000000000 +0000
+++ lib/rb/setup.rb
@@ -165,9 +165,9 @@ class ConfigTable
       libruby         = "#{c['prefix']}/lib/ruby"
       librubyver      = c['rubylibdir']
       librubyverarch  = c['archdir']
-      siteruby        = c['sitedir']
-      siterubyver     = c['sitelibdir']
-      siterubyverarch = c['sitearchdir']
+      siteruby        = c['vendordir']
+      siterubyver     = c['vendorlibdir']
+      siterubyverarch = c['vendorarchdir']
     elsif newpath_p
       # 1.4.4 <= V <= 1.6.3
       libruby         = "#{c['prefix']}/lib/ruby"
@@ -281,7 +281,6 @@ class ConfigTable
     'site-ruby-common' => 'siteruby',     # For backward compatibility
     'site-ruby'        => 'siterubyver',  # For backward compatibility
     'bin-dir'          => 'bindir',
-    'bin-dir'          => 'bindir',
     'rb-dir'           => 'rbdir',
     'so-dir'           => 'sodir',
     'data-dir'         => 'datadir',
@@ -785,7 +784,7 @@ class ToplevelInstaller
     else
       require 'rbconfig'
     end
-    ::Config::CONFIG
+    ::RbConfig::CONFIG
   end
 
   def initialize(ardir_root, config)
