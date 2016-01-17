$NetBSD: patch-unix_xserver_hw_vnc_vncModule.c,v 1.1 2016/01/17 22:01:20 joerg Exp $

--- unix/xserver/hw/vnc/vncModule.c.orig	2016-01-17 00:14:36.000000000 +0000
+++ unix/xserver/hw/vnc/vncModule.c
@@ -40,7 +40,7 @@ typedef pointer XF86OptionPtr;
 #include "RFBGlue.h"
 #include "XorgGlue.h"
 
-static void vncModuleInit(INITARGS);
+static void vncModuleInit(void);
 
 static MODULESETUPPROTO(vncSetup);
 
@@ -82,7 +82,7 @@ vncSetup(void * module, void * opts, int
     return (void *)1;
 }
 
-static void vncModuleInit(INITARGS)
+static void vncModuleInit(void)
 {
   static char once = 0;
 
