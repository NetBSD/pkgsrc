$NetBSD: patch-lib_ConvCtrl.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/ConvCtrl.c.orig	2002-10-03 09:35:27.000000000 +0000
+++ lib/ConvCtrl.c
@@ -21,6 +21,7 @@ static char *rcsid = "$Id: ConvCtrl.c,v 
 #include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
 #include <X11/Xmu/CharSet.h>
+#include <stdio.h>
 #include "ConvCtrlP.h"
 #include "InputConv.h"
 #include "ConvDisp.h"
