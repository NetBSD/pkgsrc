$NetBSD: patch-lib_rubygems_version.rb,v 1.1 2013/02/02 08:11:54 taca Exp $

A small fix from Ruby 2.0.0 and Rubygem 1.8.25.

--- lib/rubygems/version.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ lib/rubygems/version.rb
@@ -187,7 +187,7 @@ class Gem::Version
     raise ArgumentError, "Malformed version number string #{version}" unless
       self.class.correct?(version)
 
-    @version = version.to_s
+    @version = version.to_s.dup
     @version.strip!
   end
 
