$NetBSD: patch-glances_plugins_diskio_____init____.py,v 1.1 2025/11/30 15:02:29 fox Exp $

For now stub these values, so that it does not crash in NetBSD.

--- glances/plugins/diskio/__init__.py.orig	2025-11-30 14:56:51.001077556 +0000
+++ glances/plugins/diskio/__init__.py
@@ -168,6 +168,10 @@ class DiskioPlugin(GlancesPluginModel):
             # Add disk name
             stat['disk_name'] = disk_name
 
+            # For NetBSD stub the read / write time values.
+            stat['read_time'] = 0
+            stat['write_time'] = 0
+
             # Add alias if exist (define in the configuration file)
             if self.has_alias(disk_name) is not None:
                 stat['alias'] = self.has_alias(disk_name)
