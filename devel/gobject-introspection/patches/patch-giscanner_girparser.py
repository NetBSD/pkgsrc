$NetBSD: patch-giscanner_girparser.py,v 1.1 2019/06/05 09:12:32 prlw1 Exp $

cElementTree is deprecated since Python 3.3.
(gobject-introspection requires meson 0.47.0 which requires Python 3.5.)

--- giscanner/girparser.py.orig	2019-01-11 14:16:09.000000000 +0000
+++ giscanner/girparser.py
@@ -21,7 +21,7 @@
 import os
 
 from collections import OrderedDict
-from xml.etree.cElementTree import parse
+from xml.etree.ElementTree import parse
 
 from . import ast
 from .girwriter import COMPATIBLE_GIR_VERSION
