$NetBSD: patch-gpr_src_gpr-version.ads,v 1.3 2025/02/08 14:14:49 wiz Exp $

Fix incorrect version reporting

--- gpr/src/gpr-version.ads.orig	2023-10-09 21:31:11.000000000 +0300
+++ gpr/src/gpr-version.ads	2024-03-19 14:10:13.533689309 +0200
@@ -30,17 +30,17 @@
 
 package GPR.Version is
 
-   Gpr_Version : constant String := "18.0w";
+   Gpr_Version : constant String := "25.0w";
    --  Static string identifying this version
 
-   Date : constant String := "19940713";
+   Date : constant String := "20241126";
 
-   Current_Year : constant String := "2016";
+   Current_Year : constant String := "2024";
 
    type Gnat_Build_Type is (Gnatpro, FSF, GPL);
    --  See Get_Gnat_Build_Type below for the meaning of these values
 
-   Build_Type : constant Gnat_Build_Type := Gnatpro;
+   Build_Type : constant Gnat_Build_Type := FSF;
    --  Kind of GNAT Build:
    --
    --    FSF
