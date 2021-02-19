$NetBSD: patch-xml2po_xml2po_modes_mallard.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/modes/mallard.py.orig	2011-01-10 16:08:50.000000000 +0000
+++ xml2po/xml2po/modes/mallard.py
@@ -39,7 +39,7 @@ try:
 except ImportError:
     from md5 import new as md5_new
 
-from basic import basicXmlMode
+from .basic import basicXmlMode
 
 class mallardXmlMode(basicXmlMode):
     """Class for special handling of Mallard document types."""
@@ -112,7 +112,7 @@ class mallardXmlMode(basicXmlMode):
                     hash = self._md5_for_file(fullpath)
                 else:
                     hash = "THIS FILE DOESN'T EXIST"
-                    print >>sys.stderr, "Warning: image file '%s' not found." % fullpath
+                    print("Warning: image file '%s' not found." % fullpath, file=sys.stderr)
                     
                 msg.outputMessage("@@image: '%s'; md5=%s" % (attr, hash), node.lineNo(),
                                   "When image changes, this message will be marked fuzzy or untranslated for you.\n"+
