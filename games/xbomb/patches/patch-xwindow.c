$NetBSD: patch-xwindow.c,v 1.2 2021/02/10 12:12:39 nia Exp $

Avoid segfault in InitialiseX()

--- xwindow.c.orig	2014-08-15 16:25:59.000000000 +0000
+++ xwindow.c
@@ -243,7 +243,8 @@ void InitialiseX(int *argc,char **argv)
  values.font=resources.fontstruct->fid;
  for(i=0;i<NUM_GC-1;i++)
    {
-    values.foreground=resources.colours[i];
+    if(i<(sizeof(resources.colours)/sizeof(resources.colours[0])))
+      values.foreground=resources.colours[i];
     if(i==GC_UNSEEN)
       {
        GC tempgc;
