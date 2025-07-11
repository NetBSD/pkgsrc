$NetBSD: patch-Dist_xe__back.adb,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

Make gnatdist fail if compilation fails on stub/skel
https://github.com/reznikmm/garlic/commit/d037957ca6828ec3a1cced2ea64e46310f11b22d

--- Dist/xe_back.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Dist/xe_back.adb
@@ -328,7 +328,7 @@
             Arguments (3) := new String'(Name_Buffer (1 .. Name_Len));
          end if;
 
-         Compile (Full_Unit_File, Arguments, Fatal => False, Silent => True);
+         Compile (Full_Unit_File, Arguments, Fatal => True, Silent => True);
 
          Free (Arguments (3));
       elsif not Quiet_Mode then
@@ -604,7 +604,7 @@
             Arguments (3)  := new String'(Name_Buffer (1 .. Name_Len));
          end if;
 
-         Compile (Full_Unit_File, Arguments, Fatal => False, Silent => True);
+         Compile (Full_Unit_File, Arguments, Fatal => True, Silent => True);
 
          if Present (Part_Prj_Fname) then
             Free (Arguments (3));
