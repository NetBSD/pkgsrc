$NetBSD: patch-lib_mkrf_generator.rb,v 1.1 2015/06/04 13:20:11 taca Exp $

* Do not use obsolete Config but RbConfig

--- lib/mkrf/generator.rb.orig	2015-05-30 13:40:54.000000000 +0000
+++ lib/mkrf/generator.rb
@@ -41,7 +41,7 @@ module Mkrf
   class Generator
     include Rake
     
-    CONFIG = Config::CONFIG
+    CONFIG = RbConfig::CONFIG
     
     # Any extra code, given as a string, to be appended to the Rakefile.
     attr_accessor :additional_code
