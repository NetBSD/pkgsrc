$NetBSD: patch-migemo-index.rb,v 1.1 2012/08/12 11:52:26 obache Exp $

--- migemo-index.rb.orig	2003-05-26 15:45:53.000000000 +0900
+++ migemo-index.rb	2011-08-22 02:21:25.000000000 +0900
@@ -19,5 +19,5 @@
   unless line =~ /^;/
     print [offset].pack("N")
   end
-  offset += line.length
+  offset += line.bytesize
 end
