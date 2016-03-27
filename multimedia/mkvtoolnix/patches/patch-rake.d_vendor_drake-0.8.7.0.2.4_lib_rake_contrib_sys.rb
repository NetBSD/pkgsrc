$NetBSD: patch-rake.d_vendor_drake-0.8.7.0.2.4_lib_rake_contrib_sys.rb,v 1.1 2016/03/27 15:05:27 taca Exp $

Avoid to use obsolete module name.

--- rake.d/vendor/drake-0.8.7.0.2.4/lib/rake/contrib/sys.rb.orig	2011-10-09 09:48:12.000000000 +0000
+++ rake.d/vendor/drake-0.8.7.0.2.4/lib/rake/contrib/sys.rb
@@ -40,7 +40,7 @@ require 'rbconfig'
 # in Ruby 1.8.
 #
 module Sys
-  RUBY = Config::CONFIG['ruby_install_name']
+  RUBY = RbConfig::CONFIG['ruby_install_name']
 
   # Install all the files matching +wildcard+ into the +dest_dir+
   # directory.  The permission mode is set to +mode+.
