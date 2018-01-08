$NetBSD: patch-sx_pisa3_pisa__parser.py,v 1.1 2018/01/08 22:11:06 joerg Exp $

--- sx/pisa3/pisa_parser.py.orig	2018-01-08 15:08:43.919276904 +0000
+++ sx/pisa3/pisa_parser.py
@@ -26,7 +26,11 @@ import os
 import os.path
 
 import html5lib
-from html5lib import treebuilders, serializer, treewalkers, inputstream
+from html5lib import treebuilders, serializer, treewalkers
+try:
+    from html5lib import inputstream
+except ImportError:
+    from html5lib import _inputstream as inputstream
 from xml.dom import Node
 import xml.dom.minidom
 
@@ -612,9 +616,8 @@ def pisaParser(src, c, default_css="", x
                  log.error("%r is not a valid encoding", encoding)
     
     document = parser.parse(
-        src,
-        encoding=encoding)
-        
+        src)
+
     if xml_output:        
         xml_output.write(document.toprettyxml(encoding="utf8"))    
 
