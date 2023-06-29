$NetBSD: patch-lib_uri_version.rb,v 1.1 2023/06/29 15:37:17 taca Exp $

Fix for CVE-2023-36617 updating uri to 0.10.3.

--- lib/uri/version.rb.orig	2023-03-30 12:41:03.000000000 +0000
+++ lib/uri/version.rb
@@ -1,6 +1,6 @@
 module URI
   # :stopdoc:
-  VERSION_CODE = '001002'.freeze
+  VERSION_CODE = '001003'.freeze
   VERSION = VERSION_CODE.scan(/../).collect{|n| n.to_i}.join('.').freeze
   # :startdoc:
 end
