$NetBSD: patch-Garlic_s-garuni.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-garuni.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-garuni.adb
@@ -543,7 +543,7 @@
          end if;
 
          pragma Debug
-           (D ("Looking for information on unit "&  Units.Get_Name (Unit)));
+           (D ("Looking for information on unit " & Units.Get_Name (Unit)));
 
          Units.Enter;
          Current := Units.Get_Component (Unit);
