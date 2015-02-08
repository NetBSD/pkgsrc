$NetBSD: patch-unix_xserver_hw_vnc_vncHooks.cc,v 1.1 2015/02/08 19:42:09 wiz Exp $

--- unix/xserver/hw/vnc/vncHooks.cc.orig	2013-05-22 12:57:16.000000000 +0000
+++ unix/xserver/hw/vnc/vncHooks.cc
@@ -119,7 +119,7 @@ static DevPrivateKeyRec vncHooksGCKeyRec
 
 // screen functions
 
-#if XORG < 112
+#if XORG <= 112
 static Bool vncHooksCloseScreen(int i, ScreenPtr pScreen);
 #else
 static Bool vncHooksCloseScreen(ScreenPtr pScreen);
@@ -140,7 +140,7 @@ static Bool vncHooksDisplayCursor(
 				  DeviceIntPtr pDev,
 #endif
 				  ScreenPtr pScreen, CursorPtr cursor);
-#if XORG < 112
+#if XORG <= 112
 static void vncHooksBlockHandler(int i, pointer blockData, pointer pTimeout,
                                  pointer pReadmask);
 #else
@@ -367,7 +367,7 @@ Bool vncHooksInit(ScreenPtr pScreen, Xse
 // CloseScreen - unwrap the screen functions and call the original CloseScreen
 // function
 
-#if XORG < 112
+#if XORG <= 112
 static Bool vncHooksCloseScreen(int i, ScreenPtr pScreen_)
 #else
 static Bool vncHooksCloseScreen(ScreenPtr pScreen_)
@@ -405,7 +405,7 @@ static Bool vncHooksCloseScreen(ScreenPt
 
   DBGPRINT((stderr,"vncHooksCloseScreen: unwrapped screen functions\n"));
 
-#if XORG < 112
+#if XORG <= 112
   return (*pScreen->CloseScreen)(i, pScreen);
 #else
   return (*pScreen->CloseScreen)(pScreen);
@@ -574,7 +574,7 @@ static Bool vncHooksDisplayCursor(
 // BlockHandler - ignore any changes during the block handler - it's likely
 // these are just drawing the cursor.
 
-#if XORG < 112
+#if XORG <= 112
 static void vncHooksBlockHandler(int i, pointer blockData, pointer pTimeout,
                                  pointer pReadmask)
 #else
@@ -582,7 +582,7 @@ static void vncHooksBlockHandler(ScreenP
                                  pointer pReadmask)
 #endif
 {
-#if XORG < 112
+#if XORG <= 112
   SCREEN_UNWRAP(screenInfo.screens[i], BlockHandler);
 #else
   SCREEN_UNWRAP(pScreen_, BlockHandler);
@@ -590,7 +590,7 @@ static void vncHooksBlockHandler(ScreenP
 
   vncHooksScreen->desktop->ignoreHooks(true);
 
-#if XORG < 112
+#if XORG <= 112
   (*pScreen->BlockHandler) (i, blockData, pTimeout, pReadmask);
 #else
   (*pScreen->BlockHandler) (pScreen, pTimeout, pReadmask);
