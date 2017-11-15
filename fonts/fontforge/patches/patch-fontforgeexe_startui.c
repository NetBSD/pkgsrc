$NetBSD: patch-fontforgeexe_startui.c,v 1.1 2017/11/15 10:18:06 adam Exp $

Fix building on newer macOS.

--- fontforgeexe/startui.c.orig	2017-07-22 05:00:39.000000000 +0000
+++ fontforgeexe/startui.c
@@ -516,23 +516,23 @@ static  OSErr install_apple_event_handle
 
     err     = AEInstallEventHandler(kCoreEventClass, kAEOpenApplication,
                 NewAEEventHandlerUPP(OpenApplicationAE), 0, false);
-    require_noerr(err, CantInstallAppleEventHandler);
+    __Require_noErr(err, CantInstallAppleEventHandler);
 
     err     = AEInstallEventHandler(kCoreEventClass, kAEReopenApplication,
                 NewAEEventHandlerUPP(ReopenApplicationAE), 0, false);
-    require_noerr(err, CantInstallAppleEventHandler);
+    __Require_noErr(err, CantInstallAppleEventHandler);
 
     err     = AEInstallEventHandler(kCoreEventClass, kAEOpenDocuments,
                 NewAEEventHandlerUPP(OpenDocumentsAE), 0, false);
-    require_noerr(err, CantInstallAppleEventHandler);
+    __Require_noErr(err, CantInstallAppleEventHandler);
 
     err     = AEInstallEventHandler(kCoreEventClass, kAEQuitApplication,
                 NewAEEventHandlerUPP(QuitApplicationAE), 0, false);
-    require_noerr(err, CantInstallAppleEventHandler);
+    __Require_noErr(err, CantInstallAppleEventHandler);
 
     err     = AEInstallEventHandler(kCoreEventClass, kAEShowPreferences,
                 NewAEEventHandlerUPP(ShowPreferencesAE), 0, false);
-    require_noerr(err, CantInstallAppleEventHandler);
+    __Require_noErr(err, CantInstallAppleEventHandler);
 
  /* some debugging code, for now */
  if ( getenv("HOME")!=NULL ) {
