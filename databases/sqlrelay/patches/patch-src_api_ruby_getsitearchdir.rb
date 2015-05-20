$NetBSD: patch-src_api_ruby_getsitearchdir.rb,v 1.1 2015/05/20 13:26:45 ryoon Exp $

* Fix Ruby 2.2 build.

--- src/api/ruby/getsitearchdir.rb.orig	2015-04-09 01:48:10.000000000 +0000
+++ src/api/ruby/getsitearchdir.rb
@@ -1,19 +1,19 @@
 require "mkmf"
 drive = File::PATH_SEPARATOR == ";" ? /\A\w:/ : /\A/
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
-print CONFIG["prefix"].sub(drive, "").sub("$(DESTDIR)","")
+print RbConfig::CONFIG["prefix"].sub(drive, "").sub("$(DESTDIR)","")
 print "\n"
 print "exec_prefix = "
-print CONFIG["exec_prefix"].sub(drive, "").sub("$(DESTDIR)","")
+print RbConfig::CONFIG["exec_prefix"].sub(drive, "").sub("$(DESTDIR)","")
 print "\n"
 print "libdir = "
 print $libdir.sub(drive, "").sub("$(DESTDIR)","")
