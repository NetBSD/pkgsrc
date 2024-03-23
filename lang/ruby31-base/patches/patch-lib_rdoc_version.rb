$NetBSD: patch-lib_rdoc_version.rb,v 1.1 2024/03/23 14:28:48 taca Exp $

Update rdoc to 6.4.1.1 to fix for CVE-2024-27281.

--- lib/rdoc/version.rb.orig	2023-03-30 10:53:51.000000000 +0000
+++ lib/rdoc/version.rb
@@ -3,6 +3,6 @@ module RDoc
   ##
   # RDoc version you are using
 
-  VERSION = '6.4.0'
+  VERSION = '6.4.1.1'
 
 end
