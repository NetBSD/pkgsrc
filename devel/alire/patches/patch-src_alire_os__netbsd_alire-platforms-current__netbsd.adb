$NetBSD: patch-src_alire_os__netbsd_alire-platforms-current__netbsd.adb,v 1.1 2024/03/12 17:53:16 wiz Exp $

Add NetBSD support

--- /dev/null	2024-03-04 23:32:58.950570486 +0200
+++ src/alire/os_netbsd/alire-platforms-current__netbsd.adb	2024-03-04 23:47:58.197854852 +0200
@@ -0,0 +1,40 @@
+
+package body Alire.Platforms.Current is
+
+   --  NetBSD implementation (identical to FreeBSD)
+
+   ---------------------------
+   -- Detected_Distribution --
+   ---------------------------
+
+   function Detected_Distribution return Platforms.Distributions
+   is (Platforms.Distribution_Unknown);
+
+   -----------------------
+   -- Distribution_Root --
+   -----------------------
+
+   function Distribution_Root return Absolute_Path
+   is ("/");
+
+   ----------------------
+   -- Load_Environment --
+   ----------------------
+
+   procedure Load_Environment (Ctx : in out Alire.Environment.Context)
+   is null;
+
+   ----------------------
+   -- Operating_System --
+   ----------------------
+
+   function Operating_System return Alire.Platforms.Operating_Systems
+   is (Alire.Platforms.NetBSD);
+
+   ----------------
+   -- Initialize --
+   ----------------
+
+   procedure Initialize is null;
+
+end Alire.Platforms.Current;
