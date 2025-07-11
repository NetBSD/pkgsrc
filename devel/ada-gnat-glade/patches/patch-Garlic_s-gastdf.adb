$NetBSD: patch-Garlic_s-gastdf.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Garlic/s-gastdf.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gastdf.adb
@@ -36,7 +36,6 @@
 
 with GNAT.OS_Lib; use GNAT.OS_Lib;
 
-with System;
 with System.File_Control_Block;
 with System.File_IO;
 
