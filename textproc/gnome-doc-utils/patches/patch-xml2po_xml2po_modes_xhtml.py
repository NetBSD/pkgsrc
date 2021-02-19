$NetBSD: patch-xml2po_xml2po_modes_xhtml.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/modes/xhtml.py.orig	2010-12-13 16:14:07.000000000 +0000
+++ xml2po/xml2po/modes/xhtml.py
@@ -21,7 +21,7 @@
 # This implements special instructions for handling XHTML documents
 # in a better way, particularly to extract some attributes in HTML tags
 
-from basic import basicXmlMode
+from .basic import basicXmlMode
 
 class xhtmlXmlMode(basicXmlMode):
     """Class for special handling of XHTML document types."""
