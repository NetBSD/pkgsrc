$NetBSD: patch-af,v 1.1 2005/12/18 23:15:43 joerg Exp $

--- ckuusr.c.orig	2005-12-18 23:04:34.000000000 +0000
+++ ckuusr.c
@@ -87,6 +87,8 @@ char *userv = "User Interface 8.0.278, 1
 #define MULTINET_OLD_STYLE		/* Leave select prototype undefined */
 #endif /* MULTINET */
 
+#include <errno.h>
+
 #include "ckcdeb.h"
 #include "ckcasc.h"
 #include "ckcker.h"
