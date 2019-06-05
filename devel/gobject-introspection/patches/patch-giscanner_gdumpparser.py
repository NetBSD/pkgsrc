$NetBSD: patch-giscanner_gdumpparser.py,v 1.1 2019/06/05 09:12:32 prlw1 Exp $

cElementTree is deprecated since Python 3.3.
(gobject-introspection requires meson 0.47.0 which requires Python 3.5.)

--- giscanner/gdumpparser.py.orig	2019-01-16 18:03:21.000000000 +0000
+++ giscanner/gdumpparser.py
@@ -22,7 +22,7 @@ import os
 import sys
 import tempfile
 import subprocess
-from xml.etree.cElementTree import parse
+from xml.etree.ElementTree import parse
 
 from . import ast
 from . import message
