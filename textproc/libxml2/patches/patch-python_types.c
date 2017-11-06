$NetBSD: patch-python_types.c,v 1.1 2017/11/06 16:12:11 prlw1 Exp $

_PyVerify_fd disappeared from python with:

  https://hg.python.org/cpython/rev/e88e2049b793

Upstream bug:

  https://bugzilla.gnome.org/show_bug.cgi?id=776815

--- python/types.c.orig	2016-06-07 10:04:14.000000000 +0000
+++ python/types.c
@@ -31,8 +31,6 @@ libxml_PyFileGet(PyObject *f) {
     const char *mode;
 
     fd = PyObject_AsFileDescriptor(f);
-    if (!_PyVerify_fd(fd))
-        return(NULL);
     /*
      * Get the flags on the fd to understand how it was opened
      */
