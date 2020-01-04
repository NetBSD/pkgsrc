$NetBSD: patch-installer_dcheck.py,v 1.4 2020/01/04 04:24:12 khorben Exp $

Locate libraries on systems without ldconfig(8)

This only looks for libraries in pkgsrc's own library folder.

--- installer/dcheck.py.orig	2019-12-10 05:00:31.000000000 +0000
+++ installer/dcheck.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python3.7
 # -*- coding: utf-8 -*-
 #
 # (c) Copyright 2003-2015 HP Development Company, L.P.
@@ -99,11 +99,13 @@ def check_lib(lib, min_ver=0):
         #    pass
         #else:
         return True
+    elif check_file(lib+".so","/usr/pkg/lib"):
+        return True
     else:
         log.debug("Not found.")
         return False
 
-def check_file(f, dir="/usr/include"):
+def check_file(f, dir="/usr/pkg/include"):
     log.debug("Searching for file '%s' in '%s'..." % (f, dir))
     for w in utils.walkFiles(dir, recurse=True, abs_paths=True, return_folders=False, pattern=f):
         log.debug("File found at '%s'" % w)
