$NetBSD: patch-gcc_ada_libgnat_s-osprim____posix.adb,v 1.1 2024/03/08 12:02:33 wiz Exp $

Use C preprocessed symbols.

--- gcc/ada/libgnat/s-osprim__posix.adb.orig	2021-10-09 19:24:46.671910328 +0200
+++ gcc/ada/libgnat/s-osprim__posix.adb	2021-10-09 19:28:33.938823233 +0200
@@ -47,7 +47,7 @@
    pragma Convention (C, timespec);
 
    function nanosleep (rqtp, rmtp : not null access timespec) return Integer;
-   pragma Import (C, nanosleep, "nanosleep");
+   pragma Import (C, nanosleep, "__gnat_nanosleep");
 
    -----------
    -- Clock --
@@ -77,7 +77,7 @@
       function gettimeofday
         (Tv : access timeval;
          Tz : System.Address := System.Null_Address) return Integer;
-      pragma Import (C, gettimeofday, "gettimeofday");
+      pragma Import (C, gettimeofday, "__gnat_gettimeofday");
 
    begin
       --  The return codes for gettimeofday are as follows (from man pages):
