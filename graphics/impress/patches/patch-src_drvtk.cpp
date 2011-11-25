$NetBSD: patch-src_drvtk.cpp,v 1.1 2011/11/25 21:57:36 joerg Exp $

--- src/drvtk.cpp.orig	2011-11-25 18:27:54.000000000 +0000
+++ src/drvtk.cpp
@@ -26,7 +26,7 @@
 */
 
 #include "drvtk.h"
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 
