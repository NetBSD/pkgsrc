$NetBSD: patch-lib_mkrf_availability.rb,v 1.1 2015/06/04 13:20:11 taca Exp $

* Do not use obsolete Config but RbConfig

--- lib/mkrf/availability.rb.orig	2015-05-30 13:40:54.000000000 +0000
+++ lib/mkrf/availability.rb
@@ -10,14 +10,14 @@ module Mkrf
   # on the current system.
   class Availability
     # ruby 1.9+
-    if Config::CONFIG['rubyhdrdir']
-      DEFAULT_INCLUDES = [Config::CONFIG['rubyhdrdir'],
-                          Config::CONFIG['rubyhdrdir'] + "/" + Config::CONFIG['arch'],
-                          Config::CONFIG["archdir"],Config::CONFIG['sitelibdir'], "."]
+    if RbConfig::CONFIG['rubyhdrdir']
+      DEFAULT_INCLUDES = [RbConfig::CONFIG['rubyhdrdir'],
+                          RbConfig::CONFIG['rubyhdrdir'] + "/" + RbConfig::CONFIG['arch'],
+                          RbConfig::CONFIG["archdir"],RbConfig::CONFIG['sitelibdir'], "."]
 
     else
-      DEFAULT_INCLUDES = [Config::CONFIG['includedir'], Config::CONFIG["archdir"],
-                          Config::CONFIG['sitelibdir'], "."]
+      DEFAULT_INCLUDES = [RbConfig::CONFIG['includedir'], RbConfig::CONFIG["archdir"],
+                          RbConfig::CONFIG['sitelibdir'], "."]
     end
                         
     # These really shouldn't be static like this..
@@ -35,11 +35,11 @@ module Mkrf
     # * <tt>:compiler</tt> -- which compiler to use when determining availability
     # * <tt>:includes</tt> -- directories that should be searched for include files
     def initialize(options = {})      
-      @loaded_libs = [(options[:loaded_libs] || Config::CONFIG["LIBS"].gsub('-l', '').split)].flatten
+      @loaded_libs = [(options[:loaded_libs] || RbConfig::CONFIG["LIBS"].gsub('-l', '').split)].flatten
       @library_paths = [(options[:library_paths] || [])].flatten
       # Not sure what COMMON_HEADERS looks like when populated
-      @headers = options[:headers] || [] # Config::CONFIG["COMMON_HEADERS"]
-      @compiler = options[:compiler] || Config::CONFIG["CC"]
+      @headers = options[:headers] || [] # RbConfig::CONFIG["COMMON_HEADERS"]
+      @compiler = options[:compiler] || RbConfig::CONFIG["CC"]
       @includes = [(options[:includes] || DEFAULT_INCLUDES)].flatten
       @logger = Logger.new('mkrf.log')
       @defines = []
@@ -167,7 +167,7 @@ module Mkrf
       if RUBY_PLATFORM =~ /mswin/
         "link -nologo -incremental:no -debug -opt:ref -opt:icf -dll"
       else
-        Config::CONFIG['LDSHARED']
+        RbConfig::CONFIG['LDSHARED']
       end
     end
 
