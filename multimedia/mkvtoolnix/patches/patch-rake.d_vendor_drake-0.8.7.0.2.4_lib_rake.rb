$NetBSD: patch-rake.d_vendor_drake-0.8.7.0.2.4_lib_rake.rb,v 1.1 2016/03/27 15:05:27 taca Exp $

Avoid to use obsolete module name.

--- rake.d/vendor/drake-0.8.7.0.2.4/lib/rake.rb.orig	2011-10-09 09:48:12.000000000 +0000
+++ rake.d/vendor/drake-0.8.7.0.2.4/lib/rake.rb
@@ -984,13 +984,13 @@ end
 # added to the FileUtils utility functions.
 #
 module FileUtils
-  RUBY_EXT = ((Config::CONFIG['ruby_install_name'] =~ /\.(com|cmd|exe|bat|rb|sh)$/) ?
+  RUBY_EXT = ((RbConfig::CONFIG['ruby_install_name'] =~ /\.(com|cmd|exe|bat|rb|sh)$/) ?
     "" :
-    Config::CONFIG['EXEEXT'])
+    RbConfig::CONFIG['EXEEXT'])
   
   RUBY = File.join(
-    Config::CONFIG['bindir'],
-    Config::CONFIG['ruby_install_name'] + RUBY_EXT).
+    RbConfig::CONFIG['bindir'],
+    RbConfig::CONFIG['ruby_install_name'] + RUBY_EXT).
     sub(/.*\s.*/m, '"\&"')
 
   OPT_TABLE['sh']  = %w(noop verbose)
