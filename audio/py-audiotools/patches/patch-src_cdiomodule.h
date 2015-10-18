$NetBSD: patch-src_cdiomodule.h,v 1.2 2015/10/18 15:25:04 adam Exp $

Fix includes.

--- src/cdiomodule.h.orig	2015-07-08 09:42:02.000000000 +0000
+++ src/cdiomodule.h
@@ -1,11 +1,6 @@
 #include <Python.h>
-#ifdef OLD_PARANOIA
-#include <cdio/cdda.h>
-#include <cdio/paranoia.h>
-#else
-#include <cdio/cdparanoia/cdda.h>
-#include <cdio/cdparanoia/paranoia.h>
-#endif
+#include <cdio/paranoia/cdda.h>
+#include <cdio/paranoia/paranoia.h>
 
 /********************************************************
  Audio Tools, a module and set of tools for manipulating audio data
