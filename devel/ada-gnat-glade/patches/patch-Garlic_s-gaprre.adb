$NetBSD: patch-Garlic_s-gaprre.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Garlic/s-gaprre.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gaprre.adb
@@ -41,7 +41,6 @@
 with System.Garlic.Heart;             use System.Garlic.Heart;
 with System.Garlic.Options;           use System.Garlic.Options;
 with System.Garlic.Physical_Location; use System.Garlic.Physical_Location;
-with System.Garlic.Protocols;         use System.Garlic.Protocols;
 with System.Garlic.Streams;           use System.Garlic.Streams;
 with System.Garlic.Trace;             use System.Garlic.Trace;
 with System.Garlic.Types;             use System.Garlic.Types;
