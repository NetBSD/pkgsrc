$NetBSD: patch-src_alire_os__netbsd_alire-platforms-folders__netbsd.adb,v 1.2 2025/04/27 10:43:42 dkazankov Exp $

Add NetBSD support

--- /dev/null
+++ src/alire/os_netbsd/alire-platforms-folders__netbsd.adb
@@ -0,0 +1,34 @@
+with Ada.Directories;
+
+with Alire.Platforms.Common;
+
+package body Alire.Platforms.Folders is
+
+   --  NetBSD implementation
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
