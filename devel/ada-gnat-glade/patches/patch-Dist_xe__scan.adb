$NetBSD: patch-Dist_xe__scan.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe_scan.adb.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe_scan.adb
@@ -214,7 +214,8 @@
                      if Buffer (Scan_Ptr) = LF or else
                         Buffer (Scan_Ptr) = FF or else
                         Buffer (Scan_Ptr) = CR or else
-                        Buffer (Scan_Ptr) = VT then
+                        Buffer (Scan_Ptr) = VT
+                     then
                         New_Line;
                         exit;
                      elsif Buffer (Scan_Ptr) = EOF then
@@ -426,8 +427,6 @@
    procedure Write_Location
      (Where   : Location_Type) is
 
-      use ASCII;
-
    begin
       Write_Name (Configuration_File_Name);
       Write_Str (":");
