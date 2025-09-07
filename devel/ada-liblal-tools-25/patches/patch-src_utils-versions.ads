$NetBSD: patch-src_utils-versions.ads,v 1.1 2025/09/07 07:13:53 dkazankov Exp $

Set version information

--- src/utils-versions.ads.orig	2024-09-23 16:30:31.000000000 +0300
+++ src/utils-versions.ads
@@ -23,12 +23,12 @@
 
 package Utils.Versions is
 
-   Version      : constant String := "dev";
-   Current_Year : constant String := "unknown";
+   Version      : constant String := "25.0";
+   Current_Year : constant String := "2024";
 
    type Gnat_Build_Type is (Gnatpro, GPL);
 
-   Build_Type : constant Gnat_Build_Type := Gnatpro;
+   Build_Type : constant Gnat_Build_Type := GPL;
    --  Kind of GNAT Build:
    --
    --    Gnatpro
