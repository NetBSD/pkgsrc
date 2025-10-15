$NetBSD: patch-gcc_ada_libgnat_g-socthi.ads,v 1.3 2025/10/15 20:04:57 dkazankov Exp $

Fix RTS build warning

--- gcc/ada/libgnat/g-socthi.ads.orig	2025-08-08 10:24:06.091262012 +0300
+++ gcc/ada/libgnat/g-socthi.ads
@@ -53,8 +53,6 @@
 
    package C renames Interfaces.C;
 
-   use type System.CRTL.ssize_t;
-
    function Socket_Errno return Integer renames GNAT.OS_Lib.Errno;
    --  Returns last socket error number
 
