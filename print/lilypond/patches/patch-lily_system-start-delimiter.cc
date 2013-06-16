$NetBSD: patch-lily_system-start-delimiter.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/system-start-delimiter.cc.orig	2013-06-16 18:42:09.000000000 +0000
+++ lily/system-start-delimiter.cc
@@ -169,7 +169,7 @@ System_start_delimiter::staff_brace (Gro
     }
   while (hi - lo > 1);
 
-  Stencil stil (fm->find_by_name ("brace" + to_string (lo)));
+  Stencil stil (fm->find_by_name ("brace" + ::to_string (lo)));
   stil.translate_axis (-b[X_AXIS].length () / 2, X_AXIS);
 
   stil.translate_axis (-0.2, X_AXIS);
