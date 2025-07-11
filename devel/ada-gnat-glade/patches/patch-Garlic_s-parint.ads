$NetBSD: patch-Garlic_s-parint.ads,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Add PCS_Version constant to make GNAT work
https://github.com/reznikmm/garlic/commit/a7d7065148e7af5fccdbf32e03906d68a8aba65b

--- Garlic/s-parint.ads.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-parint.ads
@@ -41,6 +41,8 @@
 
    pragma Elaborate_Body;
 
+   PCS_Version : constant := 1;
+
    type DSA_Implementation_Name is (No_DSA, GARLIC_DSA, PolyORB_DSA);
    DSA_Implementation : constant DSA_Implementation_Name := GARLIC_DSA;
 
