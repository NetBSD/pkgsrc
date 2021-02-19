$NetBSD: patch-xml2po_xml2po_modes_gs.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/modes/gs.py.orig	2010-12-13 16:14:07.000000000 +0000
+++ xml2po/xml2po/modes/gs.py
@@ -20,7 +20,7 @@
 # Special case Gnome Summary
 #
 
-from basic import basicXmlMode
+from .basic import basicXmlMode
 
 class gsXmlMode(basicXmlMode):
     """Abstract class for special handling of document types."""
