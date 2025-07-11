$NetBSD: patch-Garlic_s-gaprre.ads,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation warnings for GCC 13
https://github.com/reznikmm/garlic/commit/cd21e825da1a73bd853054ea19eae6a5437fb5e4

--- Garlic/s-gaprre.ads.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-gaprre.ads
@@ -36,7 +36,6 @@
 with GNAT.Strings;
 
 with System.Garlic.Exceptions;
-with System.Garlic.Protocols;
 with System.Garlic.Types;
 
 package System.Garlic.Protocols.Replay is
