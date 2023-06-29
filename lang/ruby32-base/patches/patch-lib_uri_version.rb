$NetBSD: patch-lib_uri_version.rb,v 1.1 2023/06/29 15:42:07 taca Exp $

Fix for CVE-2023-36617 updating uri to 0.12.2.

--- lib/uri/version.rb.orig	2023-03-30 11:06:29.000000000 +0000
+++ lib/uri/version.rb
@@ -1,6 +1,6 @@
 module URI
   # :stopdoc:
-  VERSION_CODE = '001201'.freeze
+  VERSION_CODE = '001202'.freeze
   VERSION = VERSION_CODE.scan(/../).collect{|n| n.to_i}.join('.').freeze
   # :startdoc:
 end
