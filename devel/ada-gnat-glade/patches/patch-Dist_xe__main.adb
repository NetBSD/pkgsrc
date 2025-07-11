$NetBSD: patch-Dist_xe__main.adb,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe_main.adb.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe_main.adb
@@ -26,8 +26,8 @@
 
 with XE;              use XE;
 with XE_Back;         use XE_Back;
-with XE_Back.GARLIC;  use XE_Back.GARLIC;
-with XE_Back.PolyORB; use XE_Back.PolyORB;
+with XE_Back.GARLIC;
+with XE_Back.PolyORB;
 with XE_Defs;         use XE_Defs;
 with XE_Flags;        use XE_Flags;
 with XE_Front;        use XE_Front;
@@ -36,8 +36,8 @@
 with XE_Parse;        use XE_Parse;
 with XE_Types;        use XE_Types;
 with XE_Sem;          use XE_Sem;
-with XE_Scan;         use XE_Scan;
-with XE_Stdcnf;       use XE_Stdcnf;
+with XE_Scan;
+with XE_Stdcnf;
 with XE_Utils;        use XE_Utils;
 with XE_Units;        use XE_Units;
 with XE_Usage;
