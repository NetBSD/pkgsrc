$NetBSD: patch-ext_json_lib_json_version.rb,v 1.1 2013/02/12 13:03:09 taca Exp $

Fix for CVE-2013-0269.

--- ext/json/lib/json/version.rb.orig	2011-07-10 08:01:04.000000000 +0000
+++ ext/json/lib/json/version.rb
@@ -1,6 +1,6 @@
 module JSON
   # JSON version
-  VERSION         = '1.5.4'
+  VERSION         = '1.5.5'
   VERSION_ARRAY   = VERSION.split(/\./).map { |x| x.to_i } # :nodoc:
   VERSION_MAJOR   = VERSION_ARRAY[0] # :nodoc:
   VERSION_MINOR   = VERSION_ARRAY[1] # :nodoc:
