$NetBSD: patch-gui_util_misc.c,v 1.1 2025/11/15 12:43:17 ryoon Exp $

--- gui/util/misc.c.orig	2025-10-08 03:44:20.747834809 +0000
+++ gui/util/misc.c
@@ -94,7 +94,7 @@ float msf2sec(const char *msf)
         case 4:
         case 6:
         case 7:
-            if (!isdigit(msf[i]))
+            if (!isdigit((unsigned char)(msf[i])))
                 return 0.0f;
             break;
 
