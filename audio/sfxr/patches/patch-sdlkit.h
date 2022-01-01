$NetBSD: patch-sdlkit.h,v 1.1 2022/01/01 09:25:49 dholland Exp $

Use standard headers.

--- sdlkit.h~	2012-04-28 10:33:53.000000000 +0000
+++ sdlkit.h
@@ -92,7 +92,7 @@ static void ddkSetMode (int width, int h
 
 #include <gtk/gtk.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #if GTK_CHECK_VERSION(3,0,0)
 
