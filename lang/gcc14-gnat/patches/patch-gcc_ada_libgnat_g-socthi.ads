$NetBSD: patch-gcc_ada_libgnat_g-socthi.ads,v 1.2 2025/10/18 05:31:22 dkazankov Exp $

Fix RTS build warning

--- gcc/ada/libgnat/g-socthi.ads.orig	2021-10-09 18:09:40.607907149 +0200
+++ gcc/ada/libgnat/g-socthi.ads
@@ -53,8 +53,6 @@
 
    package C renames Interfaces.C;
 
-   use type System.CRTL.ssize_t;
-
    function Socket_Errno return Integer renames GNAT.OS_Lib.Errno;
    --  Returns last socket error number
