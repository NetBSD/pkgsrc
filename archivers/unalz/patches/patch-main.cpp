$NetBSD: patch-main.cpp,v 1.1 2015/11/07 20:44:23 dholland Exp $

Remove unused legacy header.

--- main.cpp~	2009-04-01 06:03:52.000000000 +0000
+++ main.cpp
@@ -49,7 +49,6 @@
 #include "UnAlz.h"
 #include "UnAlzUtils.h"
 
-#include <sys/timeb.h>
 
 
 BOOL	g_bPipeMode=FALSE;
