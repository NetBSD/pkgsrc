$NetBSD: patch-src_api_ruby_getcflags.rb,v 1.2 2015/09/02 12:39:33 fhajny Exp $

* Fix Ruby 2.2 build.

--- src/api/ruby/getcflags.rb.orig	2015-08-15 01:50:31.000000000 +0000
+++ src/api/ruby/getcflags.rb
@@ -10,7 +10,7 @@ print CONFIG["sitearch"]
 print "\n"
 print "ruby_version = "
 begin
-print Config::CONFIG["ruby_version"]
+print RbConfig::CONFIG["ruby_version"]
 rescue
 print CONFIG["ruby_version"]
 end
