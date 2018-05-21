$NetBSD: patch-LCDIS.C,v 1.1 2018/05/21 16:12:14 minskim Exp $

Don't assume a case-insensitive filesystem.

--- LCDIS.C.orig	2000-07-02 19:45:58.000000000 +0000
+++ LCDIS.C
@@ -102,7 +102,7 @@
 #include <string.h>
 #include <memory.h>
 #include <ctype.h>
-#include "lcdis.h"
+#include "LCDIS.H"
 
 // This define needed for SUN environments:
 #if (defined (sparc) || defined (__sparc__) || defined (__sparc))
