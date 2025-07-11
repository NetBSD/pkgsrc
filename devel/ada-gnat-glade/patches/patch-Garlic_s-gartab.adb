$NetBSD: patch-Garlic_s-gartab.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-gartab.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gartab.adb
@@ -209,7 +209,7 @@
             Index := Allocate;
             Table (Index) := Null_Component;
             Usage (Index).Name := Name;
-            Set_Info (Name, Integer (Integer (Index)));
+            Set_Info (Name, Integer (Index));
          else
             Index := Index_Type (Info);
          end if;
