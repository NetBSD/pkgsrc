$NetBSD: patch-src_utils.cc,v 1.1 2024/04/21 16:59:09 adam Exp $

Fix build with newer boost.

--- src/utils.cc.orig	2024-04-21 16:37:21.648652970 +0000
+++ src/utils.cc
@@ -849,7 +849,7 @@ path resolve_path(const path& pathname)
   path temp = pathname;
   if (temp.string()[0] == '~')
     temp = expand_path(temp);
-  temp.normalize();
+  temp.lexically_normal();
   return temp;
 }
 
