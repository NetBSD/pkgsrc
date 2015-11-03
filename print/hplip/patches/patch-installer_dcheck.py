$NetBSD: patch-installer_dcheck.py,v 1.2 2015/11/03 15:08:50 schnoebe Exp $

Locate libraries on systems without ldconfig(8)

This only looks for libraries in pkgsrc's own library folder.

--- installer/dcheck.py.orig	2015-06-07 19:25:11.000000000 +0000
+++ installer/dcheck.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python2.7
 # -*- coding: utf-8 -*-
 #
 # (c) Copyright 2003-2007 Hewlett-Packard Development Company, L.P.
@@ -99,6 +99,8 @@ def check_lib(lib, min_ver=0):
         #    pass
         #else:
         return True
+    elif check_file(lib+".so","/usr/lib"):
+        return True
     else:
         log.debug("Not found.")
         return False
