$NetBSD: patch-src_mapi_glapi_gen_glX__XML.py,v 1.1 2021/01/06 15:50:02 triaxx Exp $

Remove deprecated .getchildren() that are no longer supported in Python 3.9.
https://cgit.freedesktop.org/mesa/mesa/commit/src/mapi/glapi/gen/glX_XML.py?id=7a680

--- src/mapi/glapi/gen/glX_XML.py.orig	2021-01-06 15:15:12.263181000 +0100
+++ src/mapi/glapi/gen/glX_XML.py
@@ -48,7 +48,7 @@
 
         self.functions = {}
 
-        for child in element.getchildren():
+        for child in element:
             if child.tag == "size":
                 n = child.get( "name" )
                 c = child.get( "count" )
@@ -130,7 +130,7 @@
                     self.counter_list.append(param.counter)
 
 
-        for child in element.getchildren():
+        for child in element:
             if child.tag == "glx":
                 rop = child.get( 'rop' )
                 sop = child.get( 'sop' )
