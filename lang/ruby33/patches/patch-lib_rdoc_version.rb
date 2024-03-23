$NetBSD: patch-lib_rdoc_version.rb,v 1.1 2024/03/23 15:15:51 taca Exp $

Update rdoc to 6.6.3.1 to fix for CVE-2024-27281.

--- lib/rdoc/version.rb.orig	2023-12-25 05:59:38.000000000 +0000
+++ lib/rdoc/version.rb
@@ -5,6 +5,6 @@ module RDoc
   ##
   # RDoc version you are using
 
-  VERSION = '6.6.2'
+  VERSION = '6.6.3.1'
 
 end
