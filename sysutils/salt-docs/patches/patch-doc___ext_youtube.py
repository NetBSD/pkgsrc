$NetBSD: patch-doc___ext_youtube.py,v 1.1 2018/03/08 14:29:57 adam Exp $

Fix for deprecated sphinx.util.compat.Directive.

--- doc/_ext/youtube.py.orig	2018-02-28 13:14:40.000000000 +0000
+++ doc/_ext/youtube.py
@@ -37,8 +37,7 @@ from __future__ import division
 
 import re
 from docutils import nodes
-from docutils.parsers.rst import directives
-from sphinx.util.compat import Directive
+from docutils.parsers.rst import Directive, directives
 
 CONTROL_HEIGHT = 30
 
