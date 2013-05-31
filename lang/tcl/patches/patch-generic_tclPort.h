$NetBSD: patch-generic_tclPort.h,v 1.2 2013/05/31 20:15:04 adam Exp $

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
 
