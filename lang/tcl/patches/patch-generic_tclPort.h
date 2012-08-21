$NetBSD: patch-generic_tclPort.h,v 1.1 2012/08/21 21:31:47 marino Exp $

--- generic/tclPort.h.orig	2012-07-16 11:57:05.000000000 +0000
+++ generic/tclPort.h
@@ -22,7 +22,7 @@
 #endif
 #include "tcl.h"
 #if !defined(_WIN32)
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 
 #if !defined(LLONG_MIN)
