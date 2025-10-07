$NetBSD: patch-core_src_gnatcoll-io-remote-unix.adb,v 1.1 2025/10/07 20:45:10 dkazankov Exp $

Unportable fix - most close BSD variant is -T
BSD variant is -R, Linux also understands it

--- core/src/gnatcoll-io-remote-unix.adb.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/gnatcoll-io-remote-unix.adb
@@ -295,7 +295,7 @@
       Args : GNAT.OS_Lib.Argument_List :=
         (new String'("ls"),
          new String'("-l"),
-         new String'("--time-style=full-iso"),
+         new String'("-T"),
          new String'("""" & String (File) & """"),
          new String'("2>"),
          new String'("/dev/null"));
@@ -755,7 +755,7 @@
    is
       Args : GNAT.OS_Lib.Argument_List :=
         (new String'("cp"),
-         new String'("-rf"),
+         new String'("-Rf"),
          new String'("'" & String (From) & "'"),
          new String'("'" & String (Dest) & "'"));
 
