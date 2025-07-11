$NetBSD: patch-Examples_MultiPro_s-gaprxy.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Examples/MultiPro/s-gaprxy.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Examples/MultiPro/s-gaprxy.adb
@@ -43,7 +43,6 @@
 with System.Garlic.Partitions;            use System.Garlic.Partitions;
 with System.Garlic.Physical_Location;     use System.Garlic.Physical_Location;
 with System.Garlic.Platform_Specific;
-with System.Garlic.Protocols;             use System.Garlic.Protocols;
 with System.Garlic.Soft_Links;
 with System.Garlic.Streams;               use System.Garlic.Streams;
 with System.Garlic.Table;
