$NetBSD: patch-OpenGL_EGL_debug.py,v 1.1 2020/02/23 23:59:45 joerg Exp $

--- OpenGL/EGL/debug.py.orig	2020-02-22 21:14:12.920237693 +0000
+++ OpenGL/EGL/debug.py
@@ -1,3 +1,4 @@
+from __future__ import print_function
 """Debug utilities for EGL operations"""
 from OpenGL.EGL import *
 import itertools
