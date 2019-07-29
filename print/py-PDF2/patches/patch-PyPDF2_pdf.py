$NetBSD: patch-PyPDF2_pdf.py,v 1.1 2019/07/29 20:40:19 joerg Exp $

--- PyPDF2/pdf.py.orig	2019-07-29 19:44:01.901056460 +0000
+++ PyPDF2/pdf.py
@@ -2256,7 +2256,7 @@ class PageObject(DictionaryObject):
                     for ref in annots:
                         newAnnots.append(ref)
 
-        for res in "/ExtGState", "/Font", "/XObject", "/ColorSpace", "/Pattern", "/Shading", "/Properties":
+        for res in "/ExtGState", "/Font", "/XObject", "/ColorSpace", "/Pattern", "/Shading", "/Properties", "/Annots":
             new, newrename = PageObject._mergeResources(originalResources, page2Resources, res)
             if new:
                 newResources[NameObject(res)] = new
