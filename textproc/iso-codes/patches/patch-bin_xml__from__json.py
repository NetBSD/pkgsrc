$NetBSD: patch-bin_xml__from__json.py,v 1.1 2016/07/26 13:37:28 richard Exp $

Allow support for python2.7 by enforcing unicode literals and importing
from io a compatible version of open().

--- bin/xml_from_json.py.orig	2016-05-02 07:00:45.000000000 +0000
+++ bin/xml_from_json.py
@@ -1,4 +1,5 @@
 #!/usr/bin/env python3
+# -*- coding: utf-8 -*-
 #
 # Create deprecated iso-codes XML from JSON
 #
@@ -18,8 +19,11 @@
 # License along with this program; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 
+from __future__ import unicode_literals
 import json
 import sys
+if sys.version_info[0:2] == (2, 7):
+    from io import open
 
 # Get the current ISO code domain, the path to the JSON data dir, and the XML output file
 if len(sys.argv) != 4:
