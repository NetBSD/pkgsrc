$NetBSD: patch-ext_extconf.rb,v 1.1 2016/03/18 13:18:53 fhajny Exp $

Fix SunOS build with Ruby 2.3.

Upstream bug report:
https://bitbucket.org/ged/ruby-pg/issues/236

--- ext/extconf.rb.orig	2016-03-18 12:46:37.072825799 +0000
+++ ext/extconf.rb
@@ -1,6 +1,7 @@
 require 'pp'
 require 'mkmf'
 
+$CPPFLAGS << ' -D__EXTENSIONS__'
 
 if ENV['MAINTAINER_MODE']
 	$stderr.puts "Maintainer mode enabled."
