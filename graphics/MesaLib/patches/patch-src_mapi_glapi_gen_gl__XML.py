$NetBSD: patch-src_mapi_glapi_gen_gl__XML.py,v 1.1 2021/01/06 15:50:02 triaxx Exp $

Remove deprecated .getchildren() that are no longer supported in Python 3.9.
https://cgit.freedesktop.org/mesa/mesa/commit/src/mapi/glapi/gen/gl_XML.py?id=7a680

--- src/mapi/glapi/gen/gl_XML.py.orig	2021-01-06 15:17:59.922890000 +0100
+++ src/mapi/glapi/gen/gl_XML.py
@@ -713,7 +713,7 @@
 
         parameters = []
         return_type = "void"
-        for child in element.getchildren():
+        for child in element:
             if child.tag == "return":
                 return_type = child.get( "type", "void" )
             elif child.tag == "param":
@@ -743,7 +743,7 @@
                 if param.is_image():
                     self.images.append( param )
 
-        if element.getchildren():
+        if list(element):
             self.initialized = 1
             self.entry_point_parameters[name] = parameters
         else:
@@ -873,7 +873,7 @@
 
 
     def process_OpenGLAPI(self, file_name, element):
-        for child in element.getchildren():
+        for child in element:
             if child.tag == "category":
                 self.process_category( child )
             elif child.tag == "OpenGLAPI":
@@ -893,7 +893,7 @@
         [cat_type, key] = classify_category(cat_name, cat_number)
         self.categories[cat_type][key] = [cat_name, cat_number]
 
-        for child in cat.getchildren():
+        for child in cat:
             if child.tag == "function":
                 func_name = real_function_name( child )
 
