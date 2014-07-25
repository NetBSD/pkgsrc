$NetBSD: patch-extconf.rb,v 1.1 2014/07/25 16:21:26 jperkin Exp $

Do not override LDFLAGS.

--- extconf.rb.orig	2014-07-25 16:13:16.994762284 +0000
+++ extconf.rb
@@ -26,7 +26,7 @@ when 'shadow'
   #$LDFLAGS = "-lshadow"
 
   if( ! (ok &= have_library("shadow","getspent")) )
-    $LDFLAGS = ""
+    #$LDFLAGS = ""
     ok = have_func("getspent")
   end
 
