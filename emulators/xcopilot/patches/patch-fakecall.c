$NetBSD: patch-fakecall.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Include string.h for mempcy().

--- fakecall.c.orig	1998-04-25 17:59:00.000000000 +0000
+++ fakecall.c
@@ -33,6 +33,7 @@ Update History:   (most recent first)
 ******************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include "sysdeps.h"
 #include "shared.h"
 #include "memory.h"
