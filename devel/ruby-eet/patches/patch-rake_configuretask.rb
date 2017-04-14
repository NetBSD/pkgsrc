$NetBSD: patch-rake_configuretask.rb,v 1.1 2017/04/14 21:35:34 minskim Exp $

--- rake/configuretask.rb.orig	2007-03-23 11:05:12.000000000 +0000
+++ rake/configuretask.rb
@@ -244,7 +244,7 @@ module Rake
 
 				cc = ENV["CC"] || "cc"
 				flags = (ENV["CFLAGS"] || "").dup
-				flags << " -I" + Config::CONFIG["archdir"]
+				flags << " -I" + RbConfig::CONFIG["includedir"]
 
 				unless @opts[:try_link]
 					flags << " -c"
