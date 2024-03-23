$NetBSD: patch-lib_rdoc_version.rb,v 1.1 2024/03/23 14:47:13 taca Exp $

Update rdoc to 6.5.1.1 to fix for CVE-2024-27281.

--- lib/rdoc/version.rb.orig	2024-01-18 06:26:39.000000000 +0000
+++ lib/rdoc/version.rb
@@ -5,6 +5,6 @@ module RDoc
   ##
   # RDoc version you are using
 
-  VERSION = '6.5.0'
+  VERSION = '6.5.1.1'
 
 end
