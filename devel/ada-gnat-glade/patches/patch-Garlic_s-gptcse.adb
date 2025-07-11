$NetBSD: patch-Garlic_s-gptcse.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Garlic/s-gptcse.adb.orig	2007-11-26 15:35:25.000000000 +0200
+++ Garlic/s-gptcse.adb
@@ -37,7 +37,6 @@
 
 with System.Garlic.Debug;                 use System.Garlic.Debug;
 with System.Garlic.Soft_Links;            use System.Garlic.Soft_Links;
-with System.Garlic.Protocols.Tcp;         use System.Garlic.Protocols.Tcp;
 with System.Garlic.Types;                 use System.Garlic.Types;
 
 package body System.Garlic.Protocols.Tcp.Server is
