$NetBSD: patch-gnatlib-gnat_src-mlib-utl.adb,v 1.1 2013/07/09 10:16:02 marino Exp $

Use unique ada executable rather than generic gcc

--- gnatlib/gnat_src/mlib-utl.adb.orig	2010-02-14 02:40:00.000000000 +0100
+++ gnatlib/gnat_src/mlib-utl.adb	2011-10-09 04:11:21.000000000 +0200
@@ -412,7 +412,7 @@
       if Driver_Name = No_Name then
          if Gcc_Exec = null then
             if Gcc_Name = null then
-               Gcc_Name := Osint.Program_Name ("gcc", "gnatmake");
+               Gcc_Name := Osint.Program_Name ("ada", "gnatmake");
             end if;
 
             Gcc_Exec := Locate_Exec_On_Path (Gcc_Name.all);
