$NetBSD: patch-scipy_stats__unuran_setup.py,v 1.2 2023/05/05 14:59:25 adam Exp $

On NetBSD/powerpc, you can't build with _ISOC99_SOURCE defined,
the include of <ieeefp.h> deep down in the python headers will fail
with undefined types.

--- scipy/stats/_unuran/setup.py.orig	2022-05-16 12:36:53.864307900 +0000
+++ scipy/stats/_unuran/setup.py
@@ -95,7 +95,6 @@ def configuration(parent_package="", top
         ("UNUR_ENABLE_INFO", "1"),
         ("VERSION", '"%s"' % UNURAN_VERSION),
         ("HAVE_CONFIG_H", "1"),
-        ("_ISOC99_SOURCE", "1"),
     ]
 
     UNURAN_DIRS = [
