$NetBSD: patch-doc___ext_saltdomain.py,v 1.1 2018/10/25 09:09:35 adam Exp $

Do not import Directive twice.

--- doc/_ext/saltdomain.py.orig	2018-10-25 07:52:41.000000000 +0000
+++ doc/_ext/saltdomain.py
@@ -7,7 +7,7 @@ from docutils.parsers.rst import Directi
 
 from docutils.statemachine import ViewList
 from sphinx import addnodes
-from sphinx.directives import ObjectDescription, Directive
+from sphinx.directives import ObjectDescription
 from sphinx.domains import Domain, ObjType
 from sphinx.domains.python import PyObject
 from sphinx.locale import l_, _
