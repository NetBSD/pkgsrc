$NetBSD: patch-src_xye__script.cpp,v 1.1 2025/02/09 08:45:39 triaxx Exp $

Avoid ambiguity with std::lock.

--- src/xye_script.cpp.orig	2025-02-09 07:35:18.118738041 +0000
+++ src/xye_script.cpp
@@ -859,7 +859,7 @@ void Load_Lock(TiXmlElement* el)
         el->QueryIntAttribute("x",&LastX);
         el->QueryIntAttribute("y",&LastY);
         blockcolor c=GetElementBlockColor(el);
-    lock* bc=new lock(game::SquareN(LastX,LastY),c);
+        xye_lock* bc=new xye_lock(game::SquareN(LastX,LastY),c);
 }
 
 /* Load Key*/
