$NetBSD: patch-unix_xserver_hw_vnc_vncModule.c,v 1.2 2018/08/17 12:36:05 wiz Exp $

--- unix/xserver/hw/vnc/vncModule.c.orig	2018-07-16 14:08:55.000000000 +0000
+++ unix/xserver/hw/vnc/vncModule.c
@@ -39,7 +39,7 @@ typedef pointer XF86OptionPtr;
 #include "XorgGlue.h"
 #include "RandrGlue.h"
 
-static void vncModuleInit(INITARGS);
+static void vncModuleInit(void);
 
 static MODULESETUPPROTO(vncSetup);
 
@@ -81,7 +81,7 @@ vncSetup(void * module, void * opts, int
     return (void *)1;
 }
 
-static void vncModuleInit(INITARGS)
+static void vncModuleInit(void)
 {
   static char once = 0;
 
