$NetBSD: patch-src_alire_os__netbsd_alire-check__absolute__path.adb,v 1.1 2024/03/12 17:53:16 wiz Exp $

Add NetBSD support

--- /dev/null	2023-12-27 21:54:28.155585723 +0200
+++ src/alire/os_netbsd/alire-check_absolute_path.adb	2023-10-19 18:04:21.000000000 +0300
@@ -0,0 +1,7 @@
+separate (Alire)
+function Check_Absolute_Path (Path : Any_Path) return Boolean is
+begin
+   return (Path'Length >= 1
+            and then
+           Path (Path'First) = GNAT.OS_Lib.Directory_Separator);
+end Check_Absolute_Path;
