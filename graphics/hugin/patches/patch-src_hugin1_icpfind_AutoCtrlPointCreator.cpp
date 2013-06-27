$NetBSD: patch-src_hugin1_icpfind_AutoCtrlPointCreator.cpp,v 1.1 2013/06/27 15:51:49 joerg Exp $

--- src/hugin1/icpfind/AutoCtrlPointCreator.cpp.orig	2013-06-25 22:01:10.000000000 +0000
+++ src/hugin1/icpfind/AutoCtrlPointCreator.cpp
@@ -28,9 +28,6 @@
 #include "panoinc.h"
 
 #include <fstream>
-#ifdef __GNUC__
-#include <ext/stdio_filebuf.h>
-#endif
 
 #include "PT/Panorama.h"
 #include "PT/ImageGraph.h"
