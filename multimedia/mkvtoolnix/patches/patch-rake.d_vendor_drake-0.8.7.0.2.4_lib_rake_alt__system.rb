$NetBSD: patch-rake.d_vendor_drake-0.8.7.0.2.4_lib_rake_alt__system.rb,v 1.1 2016/03/27 15:05:27 taca Exp $

Avoid to use obsolete module name.

--- rake.d/vendor/drake-0.8.7.0.2.4/lib/rake/alt_system.rb.orig	2011-10-09 09:48:12.000000000 +0000
+++ rake.d/vendor/drake-0.8.7.0.2.4/lib/rake/alt_system.rb
@@ -29,7 +29,7 @@ require 'rbconfig'
 # for ruby-1.8 and earlier.
 # 
 module Rake::AltSystem
-  WINDOWS = Config::CONFIG["host_os"] =~ %r!(msdos|mswin|djgpp|mingw)!
+  WINDOWS = RbConfig::CONFIG["host_os"] =~ %r!(msdos|mswin|djgpp|mingw)!
 
   class << self
     def define_module_function(name, &block)
