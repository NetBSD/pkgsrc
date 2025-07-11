$NetBSD: patch-Garlic_s-gartas.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Garlic/s-gartas.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gartas.adb
@@ -35,7 +35,6 @@
 with Ada.Dynamic_Priorities;
 --  with Ada.Task_Attributes;
 
-with System;                     use System;
 with System.Garlic.Debug;        use System.Garlic.Debug;
 with System.Garlic.Soft_Links;   use System.Garlic.Soft_Links;
 with System.Garlic.Types;        use System.Garlic.Types;
