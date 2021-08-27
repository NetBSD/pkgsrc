$NetBSD: patch-mx_test__filesel.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Include string.h for strcpy().

--- mx/test_filesel.c.orig	1998-08-21 00:56:14.000000000 +0000
+++ mx/test_filesel.c
@@ -19,6 +19,7 @@ Update History:   (most recent first)
 
 ******************************************************************************/
 #include <stdio.h>
+#include <string.h>
 #include "libmx.h"
 
 #define MAIN_N_ITEMS 4
