$NetBSD: patch-xml2po_xml2po_modes_ubuntu.py,v 1.1 2021/02/19 10:42:54 nia Exp $

Python 3 support.

via Fedora and a million other Linux distributions:
https://src.fedoraproject.org/rpms/gnome-doc-utils/tree/rawhide

--- xml2po/xml2po/modes/ubuntu.py.orig	2010-12-13 16:14:07.000000000 +0000
+++ xml2po/xml2po/modes/ubuntu.py
@@ -2,7 +2,7 @@
 
 import libxml2
 
-from docbook import docbookXmlMode
+from .docbook import docbookXmlMode
 
 class ubuntuXmlMode (docbookXmlMode):
     """Special-casing Ubuntu DocBook website documentation."""
