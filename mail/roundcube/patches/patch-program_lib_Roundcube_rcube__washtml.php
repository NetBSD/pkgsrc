$NetBSD: patch-program_lib_Roundcube_rcube__washtml.php,v 1.3.2.2 2016/06/04 19:39:34 bsiegert Exp $

Fix CVE-2016-5103, XSS from upstream.

--- program/lib/Roundcube/rcube_washtml.php.orig	2016-04-17 16:22:20.000000000 +0000
+++ program/lib/Roundcube/rcube_washtml.php
@@ -370,7 +370,7 @@ class rcube_washtml
      */
     private function is_link_attribute($tag, $attr)
     {
-        return $tag == 'a' && $attr == 'href';
+        return ($tag == 'a' || $tag == 'area') && $attr == 'href';
     }
 
     /**
