$NetBSD: patch-src_api_ruby_getcflags.rb,v 1.1 2015/05/20 13:26:45 ryoon Exp $

* Fix Ruby 2.2 build.

--- src/api/ruby/getcflags.rb.orig	2011-07-16 00:49:53.000000000 +0000
+++ src/api/ruby/getcflags.rb
@@ -6,19 +6,19 @@ require "mkmf"
 drive = File::PATH_SEPARATOR == ";" ? /\A\w:/ : /\A/
 print "\n"
 print "arch = "
-print CONFIG["arch"]
+print RbConfig::CONFIG["arch"]
 print "\n"
 print "sitearch = "
-print CONFIG["sitearch"]
+print RbConfig::CONFIG["sitearch"]
 print "\n"
 print "ruby_version = "
-print Config::CONFIG["ruby_version"]
+print RbConfig::CONFIG["ruby_version"]
 print "\n"
 print "prefix = "
-print CONFIG["prefix"].sub(drive, "")
+print RbConfig::CONFIG["prefix"].sub(drive, "")
 print "\n"
 print "exec_prefix = "
-print CONFIG["exec_prefix"].sub(drive, "")
+print RbConfig::CONFIG["exec_prefix"].sub(drive, "")
 print "\n"
 print "libdir = "
 print $libdir.sub(drive, "")
