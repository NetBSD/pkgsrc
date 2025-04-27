$NetBSD: patch-src_alire_os__netbsd_alire-platforms-current__netbsd.adb,v 1.2 2025/04/27 10:43:42 dkazankov Exp $

Add NetBSD support

--- /dev/null
+++ src/alire/os_netbsd/alire-platforms-current__netbsd.adb
@@ -0,0 +1,40 @@
+
+package body Alire.Platforms.Current is
+
+   --  NetBSD implementation (very close to Linux/FreeBSD/OpenBSD)
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
