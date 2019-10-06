$NetBSD: patch-xwindow.c,v 1.1 2019/10/06 14:41:07 jakllsch Exp $

Avoid segfault in InitialiseX()

--- xwindow.c.orig	2008-01-05 19:24:16.000000000 +0000
+++ xwindow.c
@@ -245,7 +245,8 @@ void InitialiseX(int *argc,char **argv)
  values.font=resources.fontstruct->fid;
  for(i=0;i<NUM_GC;i++)
    {
-    values.foreground=resources.colours[i];
+    if(i<(sizeof(resources.colours)/sizeof(resources.colours[0])))
+       values.foreground=resources.colours[i];
     if(i==GC_UNSEEN)
       {
        GC tempgc;
