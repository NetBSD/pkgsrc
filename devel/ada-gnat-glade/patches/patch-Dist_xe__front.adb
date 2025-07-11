$NetBSD: patch-Dist_xe__front.adb,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe_front.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Dist/xe_front.adb
@@ -470,7 +470,8 @@
          HID := Partitions.Table (P).Host;
          if HID /= No_Host_Id
            and then not Hosts.Table (HID).Static
-           and then Hosts.Table (HID).Import = Ada_Import then
+           and then Hosts.Table (HID).Import = Ada_Import
+         then
             Add_Conf_Unit (Hosts.Table (HID).External, P);
          end if;
       end loop;
