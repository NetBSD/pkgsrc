$NetBSD: patch-gpr_src_gpr-util-put__resource__usage____unix.adb,v 1.2 2025/02/08 14:14:49 wiz Exp $

Fix warning at link stage on NetBSD

--- gpr/src/gpr-util-put_resource_usage__unix.adb.orig	2023-10-09 21:31:11.000000000 +0300
+++ gpr/src/gpr-util-put_resource_usage__unix.adb	2024-05-07 10:36:42.700699231 +0300
@@ -69,7 +69,7 @@
       procedure Print (This : STC.Timeval);
 
       function Getrusage (Who : Integer; usage : out Rusage) return Integer
-        with Import, Convention => C;
+        with Import, Convention => C, External_Name => "__netbsd_getrusage";
 
       -----------
       -- Print --
