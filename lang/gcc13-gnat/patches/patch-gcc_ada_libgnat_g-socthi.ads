$NetBSD: patch-gcc_ada_libgnat_g-socthi.ads,v 1.1 2024/03/08 12:02:33 wiz Exp $

Fix symbol to make it use the C processed one.

--- gcc/ada/libgnat/g-socthi.ads.orig	2021-10-09 18:09:40.607907149 +0200
+++ gcc/ada/libgnat/g-socthi.ads	2021-10-09 18:24:39.373733909 +0200
@@ -53,8 +53,6 @@
 
    package C renames Interfaces.C;
 
-   use type System.CRTL.ssize_t;
-
    function Socket_Errno return Integer renames GNAT.OS_Lib.Errno;
    --  Returns last socket error number
 
@@ -256,7 +254,7 @@
    pragma Import (C, C_Getsockname, "getsockname");
    pragma Import (C, C_Getsockopt, "getsockopt");
    pragma Import (C, C_Listen, "listen");
-   pragma Import (C, C_Select, "select");
+   pragma Import (C, C_Select, "__gnat_select");
    pragma Import (C, C_Setsockopt, "setsockopt");
    pragma Import (C, C_Shutdown, "shutdown");
    pragma Import (C, C_Socketpair, "socketpair");
