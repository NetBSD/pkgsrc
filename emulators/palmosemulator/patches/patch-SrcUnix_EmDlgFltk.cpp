$NetBSD: patch-SrcUnix_EmDlgFltk.cpp,v 1.1 2012/06/19 20:29:35 asau Exp $

Define PATH_MAX.

--- SrcUnix/EmDlgFltk.cpp.orig	2002-03-29 13:11:19.000000000 +0000
+++ SrcUnix/EmDlgFltk.cpp
@@ -11,6 +11,8 @@
 	(at your option) any later version.
 \* ===================================================================== */
 
+#include <limits.h>
+
 #include "EmCommon.h"
 #include "EmDlgFltk.h"
 
