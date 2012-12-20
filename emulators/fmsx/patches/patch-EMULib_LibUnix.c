$NetBSD: patch-EMULib_LibUnix.c,v 1.1 2012/12/20 21:57:52 joerg Exp $

--- EMULib/LibUnix.c.orig	2012-12-20 12:25:35.000000000 +0000
+++ EMULib/LibUnix.c
@@ -12,6 +12,8 @@
 /*************************************************************/
 #include "EMULib.h"
 
+#include <unistd.h>
+#include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -142,7 +144,7 @@ int ShowVideo(void)
     else
 #endif
       XPutImage(Dsp,Wnd,DefaultGCOfScreen(Scr),VideoImg->XImg,VideoX,VideoY,(XSize-VideoW)>>1,(YSize-VideoH)>>1,VideoW,VideoH);
-    return;
+    return 0;
   }
 
   /* Scale video buffer into OutImg */
@@ -159,6 +161,7 @@ int ShowVideo(void)
   else
 #endif
     XPutImage(Dsp,Wnd,DefaultGCOfScreen(Scr),OutImg.XImg,0,0,0,0,XSize,YSize);
+  return 0;
 }
 
 /** GetJoystick() ********************************************/
