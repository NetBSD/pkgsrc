$NetBSD: patch-setup_install.py,v 1.3 2022/01/09 15:43:51 rhialto Exp $

This line gets replaced to a full python path by the pkgsrc
infrastructure, avoid appending a number to that.

--- setup/install.py.orig	2020-02-21 03:27:12.000000000 +0000
+++ setup/install.py
@@ -20,7 +20,7 @@ from setup import (
 )
 
 HEADER = '''\
-#!/usr/bin/env python{py_major_version}
+#!/usr/bin/env python
 
 """
 This is the standard runscript for all of calibre's tools.
