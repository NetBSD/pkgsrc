$NetBSD: patch-lily_rest.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/rest.cc.orig	2013-06-16 19:00:53.000000000 +0000
+++ lily/rest.cc
@@ -169,7 +169,7 @@ Rest::glyph_name (Grob *me, int durlog, 
       actual_style = "";
     }
 
-  return ("rests." + to_string (durlog) + (is_ledgered ? "o" : "")
+  return ("rests." + ::to_string (durlog) + (is_ledgered ? "o" : "")
           + actual_style);
 }
 
