$NetBSD: patch-compilers_gnatdist_xe__back-garlic.adb,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix include/library paths
Fix params for gprbuild

--- compilers/gnatdist/xe_back-garlic.adb.orig	2024-08-23 19:03:44.000000000 +0300
+++ compilers/gnatdist/xe_back-garlic.adb
@@ -194,8 +194,10 @@
    --  Take a unit id and return its name removing unit suffix.
 
    DSA_Inc_Rel_Dir : constant String :=
-                      "lib" & Directory_Separator & "garlic";
+                      "include" & Directory_Separator & "garlic";
    --  GARLIC include directory, relative to the installation prefix
+   DSA_Lib_Rel_Dir : constant String :=
+                      "lib" & Directory_Separator & "garlic";
 
    GARLIC_Prefix : constant String :=
                      XE_Back.Prefix
@@ -203,6 +205,7 @@
                                       & Dir_Separator & "s-garlic.ads");
 
    DSA_Inc_Dir : constant String := GARLIC_Prefix & DSA_Inc_Rel_Dir;
+   DSA_Lib_Dir : constant String := GARLIC_Prefix & DSA_Lib_Rel_Dir;
 
    ------------------
    -- Add_Protocol --
@@ -1346,10 +1349,12 @@
          raise Fatal_Error with "GARLIC library not found";
       end if;
 
+      if not Use_GPRBuild then
       Scan_Dist_Arg ("-aI" & DSA_Inc_Dir);
-      Scan_Dist_Arg ("-aO" & DSA_Inc_Dir);
+         Scan_Dist_Arg ("-aO" & DSA_Lib_Dir);
+      end if;
       Scan_Dist_Arg ("-largs");
-      Scan_Dist_Arg ("-L" & DSA_Inc_Dir);
+      Scan_Dist_Arg ("-L" & DSA_Lib_Dir);
       Scan_Dist_Arg ("-lgarlic");
    end Set_PCS_Dist_Flags;
 
