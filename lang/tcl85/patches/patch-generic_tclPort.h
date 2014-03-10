$NetBSD: patch-generic_tclPort.h,v 1.1 2014/03/10 14:20:44 taca Exp $

Use relative path to include.

--- generic/tclPort.h.orig	2013-03-21 12:57:40.000000000 +0000
+++ generic/tclPort.h
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
 
