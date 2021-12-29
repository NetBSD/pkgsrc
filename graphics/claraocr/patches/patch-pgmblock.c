$NetBSD: patch-pgmblock.c,v 1.1 2021/12/29 09:18:42 dholland Exp $

Fix invalid calls to open(2).

--- pgmblock.c~	2002-04-29 14:26:13.000000000 +0000
+++ pgmblock.c
@@ -161,7 +161,7 @@ void pgmmap(unsigned char *pb,int w,int 
 
         printf("%d rare pixels (%1.4f)\n",t,((float)t)/(w*h));
 
-        F = open("map",O_WRONLY|O_CREAT);
+        F = open("map",O_WRONLY|O_CREAT, 0664);
         write(F,m,h*bpl);
         write(F,map,256);
         close(F);
@@ -197,7 +197,7 @@ void pgmunmap(unsigned char *pb,int w,in
     {
         int i,j,F;
 
-        F = open("map",O_RDONLY|O_CREAT);
+        F = open("map",O_RDONLY);
         read(F,m,h*bpl);
         read(F,map,256);
         close(F);
