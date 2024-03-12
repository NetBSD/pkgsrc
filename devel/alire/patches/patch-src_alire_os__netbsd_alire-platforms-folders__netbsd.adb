$NetBSD: patch-src_alire_os__netbsd_alire-platforms-folders__netbsd.adb,v 1.1 2024/03/12 17:53:16 wiz Exp $

Add NetBSD support

--- /dev/null	2024-03-04 23:32:58.950570486 +0200
+++ src/alire/os_netbsd/alire-platforms-folders__netbsd.adb	2024-03-04 23:27:09.298953043 +0200
@@ -0,0 +1,34 @@
+with Ada.Directories;
+
+with Alire.Platforms.Common;
+
+package body Alire.Platforms.Folders is
+
+   --  Linux implementation
+
+   -----------
+   -- Cache --
+   -----------
+
+   function Cache return Absolute_Path is (Common.XDG_Data_Home);
+
+   -----------
+   -- Config--
+   -----------
+
+   function Config return Absolute_Path is (Common.XDG_Config_Home);
+
+   ----------
+   -- Home --
+   ----------
+
+   function Home return Absolute_Path is (Common.Unix_Home_Folder);
+
+   ----------
+   -- Temp --
+   ----------
+
+   function Temp return Absolute_Path
+   is (Ada.Directories.Full_Name (Common.Unix_Temp_Folder));
+
+end Alire.Platforms.Folders;
