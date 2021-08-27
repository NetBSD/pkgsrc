$NetBSD: patch-mx_request.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Include string.h for strlen().

--- mx/request.c.orig	1998-04-25 17:50:15.000000000 +0000
+++ mx/request.c
@@ -17,6 +17,7 @@ Update History:   (most recent first)
 
 ******************************************************************************/
 
+#include <string.h>
 #include "basic.h"
 #include "X11/keysym.h"
 #include "alert.h"
