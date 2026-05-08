$NetBSD: patch-src_gui_macutilities.mm,v 1.1 2026/05/08 14:24:05 adam Exp $

Disable notifications as these make the app crash when it is not bundled.

--- src/gui/macutilities.mm.orig	2026-05-05 07:36:13.433945442 +0000
+++ src/gui/macutilities.mm
@@ -92,6 +92,7 @@ namespace MacUtils
 
     void askForNotificationPermission()
     {
+/*
         @autoreleasepool
         {
             [UNUserNotificationCenter.currentNotificationCenter requestAuthorizationWithOptions:
@@ -105,10 +106,12 @@ namespace MacUtils
                                 }
                             }];
         }
+*/
     }
 
     void displayNotification(const QString &title, const QString &message)
     {
+/*
         @autoreleasepool
         {
             UNMutableNotificationContent *content = [[UNMutableNotificationContent alloc] init];
@@ -121,6 +124,7 @@ namespace MacUtils
             [UNUserNotificationCenter.currentNotificationCenter
                 addNotificationRequest:request withCompletionHandler:nil];
         }
+*/
     }
 
     void openFiles(const PathList &pathList)
