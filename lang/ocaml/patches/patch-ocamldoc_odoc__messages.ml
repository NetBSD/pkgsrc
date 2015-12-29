$NetBSD: patch-ocamldoc_odoc__messages.ml,v 1.3 2015/12/29 23:34:53 dholland Exp $

Put man pages in section 3 rather than 3o

--- ocamldoc/odoc_messages.ml.orig	2014-09-26 13:00:20.000000000 +0000
+++ ocamldoc/odoc_messages.ml
@@ -89,7 +89,7 @@ let default_man_section = "3"
 let man_section = "<section> Use <section> in man page files "^
   "(default is "^default_man_section^") "^man_only^"\n"
 
-let default_man_suffix = default_man_section^"o"
+let default_man_suffix = default_man_section
 let man_suffix = "<suffix> Use <suffix> for man page files "^
   "(default is "^default_man_suffix^") "^man_only^"\n"
 
