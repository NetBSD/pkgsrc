$NetBSD: patch-Dist_xe__usage.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Update version

--- Dist/xe_usage.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Dist/xe_usage.adb
@@ -29,7 +29,7 @@
 with XE_Flags; use XE_Flags;
 
 procedure XE_Usage is
-   Version : constant String := "5.04w";
+   Version : constant String := "6.0w";
    Length  : Positive := Version'First;
 
 begin
