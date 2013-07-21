$NetBSD: patch-lib_rubygems_ext_ext__conf__builder.rb,v 1.1 2013/07/21 02:32:58 taca Exp $

* Expicitly remove a temporary file.

--- lib/rubygems/ext/ext_conf_builder.rb.orig	2013-03-17 15:13:08.000000000 +0000
+++ lib/rubygems/ext/ext_conf_builder.rb
@@ -49,6 +49,7 @@ class Gem::Ext::ExtConfBuilder < Gem::Ex
 
         results
       ensure
+        siteconf.close true
         ENV["RUBYOPT"] = rubyopt
         ENV["DESTDIR"] = destdir
       end
