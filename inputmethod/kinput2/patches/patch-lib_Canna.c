$NetBSD: patch-lib_Canna.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/Canna.c.orig	2002-10-03 09:35:27.000000000 +0000
+++ lib/Canna.c
@@ -58,6 +58,7 @@ static char *rcsid = "$Id: Canna.c,v 1.5
 #if XtSpecificationRelease > 4
 #include <X11/Xfuncs.h>
 #endif
+#include <stdlib.h>
 #include "CannaP.h"
 #include "DebugPrint.h"
 
