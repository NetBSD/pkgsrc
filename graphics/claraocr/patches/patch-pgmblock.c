$NetBSD: patch-pgmblock.c,v 1.2 2026/03/18 10:08:44 nia Exp $

Fix invalid calls to open(2).

--- pgmblock.c.orig	2002-04-29 14:26:13.000000000 +0000
+++ pgmblock.c
@@ -28,6 +28,9 @@ pgmblock.c: grayscale loading and blockf
 #include <stdlib.h>
 #include <math.h>
 #include <unistd.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include "common.h"
 #include "gui.h"
 
@@ -161,7 +164,7 @@ void pgmmap(unsigned char *pb,int w,int 
 
         printf("%d rare pixels (%1.4f)\n",t,((float)t)/(w*h));
 
-        F = open("map",O_WRONLY|O_CREAT);
+        F = open("map",O_WRONLY|O_CREAT, 0664);
         write(F,m,h*bpl);
         write(F,map,256);
         close(F);
@@ -197,7 +200,7 @@ void pgmunmap(unsigned char *pb,int w,in
     {
         int i,j,F;
 
-        F = open("map",O_RDONLY|O_CREAT);
+        F = open("map",O_RDONLY);
         read(F,m,h*bpl);
         read(F,map,256);
         close(F);
