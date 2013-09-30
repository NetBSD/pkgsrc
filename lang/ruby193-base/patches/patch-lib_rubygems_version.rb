$NetBSD: patch-lib_rubygems_version.rb,v 1.3 2013/09/30 03:15:03 taca Exp $

* A fix for CVE-2013-4363.
* A small fix from Ruby 2.0.0 and Rubygem 1.8.25.

--- lib/rubygems/version.rb.orig	2012-04-19 22:43:16.000000000 +0000
+++ lib/rubygems/version.rb
@@ -145,8 +145,8 @@ class Gem::Version
 
   include Comparable
 
-  VERSION_PATTERN = '[0-9]+(\.[0-9a-zA-Z]+)*' # :nodoc:
-  ANCHORED_VERSION_PATTERN = /\A\s*(#{VERSION_PATTERN})*\s*\z/ # :nodoc:
+  VERSION_PATTERN = '[0-9]+(?>\.[0-9a-zA-Z]+)*' # :nodoc:
+  ANCHORED_VERSION_PATTERN = /\A\s*(#{VERSION_PATTERN})?\s*\z/ # :nodoc:
 
   ##
   # A string representation of this Version.
@@ -187,7 +187,7 @@ class Gem::Version
     raise ArgumentError, "Malformed version number string #{version}" unless
       self.class.correct?(version)
 
-    @version = version.to_s
+    @version = version.to_s.dup
     @version.strip!
   end
 
