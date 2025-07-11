$NetBSD: patch-Dist_xe__back-garlic.adb,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

Fix some compilation warnings

--- Dist/xe_back-garlic.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Dist/xe_back-garlic.adb
@@ -34,9 +34,6 @@
 with XE_Names;    use XE_Names;
 with XE_Utils;    use XE_Utils;
 
-with XE_Back;
-pragma Elaborate_All (XE_Back);
-
 package body XE_Back.GARLIC is
 
    type GARLIC_Backend is new Backend with null record;
