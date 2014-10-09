$NetBSD: patch-src_cdiomodule.h,v 1.1 2014/10/09 12:44:37 adam Exp $

Fix for newer libcdio-paranoia.

--- src/cdiomodule.h.orig	2014-10-09 12:37:31.000000000 +0000
+++ src/cdiomodule.h
@@ -1,6 +1,6 @@
 #include <Python.h>
-#include <cdio/cdda.h>
-#include <cdio/paranoia.h>
+#include <cdio/paranoia/cdda.h>
+#include <cdio/paranoia/paranoia.h>
 #include "array.h"
 
 /********************************************************
