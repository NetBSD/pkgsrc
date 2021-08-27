$NetBSD: patch-mx_basic.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Include string.h for strlen().

--- mx/basic.c.orig	1998-05-07 17:48:26.000000000 +0000
+++ mx/basic.c
@@ -17,6 +17,7 @@ Update History:   (most recent first)
 
 ******************************************************************************/
 #include <stdlib.h>
+#include <string.h>
 #include "X11/Xlib.h"
 #include "X11/Xutil.h"
 #include "X11/cursorfont.h"
