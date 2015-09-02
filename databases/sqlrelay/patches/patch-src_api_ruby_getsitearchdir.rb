$NetBSD: patch-src_api_ruby_getsitearchdir.rb,v 1.2 2015/09/02 12:39:33 fhajny Exp $

* Fix Ruby 2.2 build.

--- src/api/ruby/getsitearchdir.rb.orig	2015-08-15 00:27:59.000000000 +0000
+++ src/api/ruby/getsitearchdir.rb
@@ -1,35 +1,35 @@
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
 begin
-print Config::CONFIG["ruby_version"]
+print RbConfig::CONFIG["ruby_version"]
 rescue
-print CONFIG["ruby_version"]
+print RbConfig::CONFIG["ruby_version"]
 end
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
 print "\n"
-if CONFIG["RUBY_BASE_NAME"]!=nil then
+if RbConfig::CONFIG["RUBY_BASE_NAME"]!=nil then
 	print "RUBY_BASE_NAME = "
-	print CONFIG["RUBY_BASE_NAME"]
+	print RbConfig::CONFIG["RUBY_BASE_NAME"]
 	print "\n"
 end
-if CONFIG["rubylibprefix"]!=nil then
+if RbConfig::CONFIG["rubylibprefix"]!=nil then
 	print "rubylibprefix = "
-	print CONFIG["rubylibprefix"].sub(drive, "").sub("$(DESTDIR)","")
+	print RbConfig::CONFIG["rubylibprefix"].sub(drive, "").sub("$(DESTDIR)","")
 	print "\n"
 end
 print "rubylibdir = "
