$NetBSD: patch-gcc_ada_libgnat_s-osprim____posix.adb,v 1.2 2025/02/08 14:05:03 wiz Exp $

Use C preprocessed symbols.

--- gcc/ada/libgnat/s-osprim__posix.adb.orig	2024-05-21 10:47:38.000000000 +0300
+++ gcc/ada/libgnat/s-osprim__posix.adb
@@ -49,7 +49,7 @@
    pragma Convention (C, timespec);
 
    function nanosleep (rqtp, rmtp : not null access timespec) return Integer;
-   pragma Import (C, nanosleep, "nanosleep");
+   pragma Import (C, nanosleep, "__gnat_nanosleep");
 
    -----------
    -- Clock --
@@ -79,7 +79,7 @@
       function gettimeofday
         (Tv : access timeval;
          Tz : System.Address := System.Null_Address) return Integer;
-      pragma Import (C, gettimeofday, "gettimeofday");
+      pragma Import (C, gettimeofday, "__gnat_gettimeofday");
 
    begin
       --  The return codes for gettimeofday are as follows (from man pages):
