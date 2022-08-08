$NetBSD: patch-glances_plugins_glances__quicklook.py,v 1.3 2022/08/08 09:28:06 fox Exp $

It seems cpu_hz_current and cpu_hz is not available in NetBSD, so add additional
check to see if the key exists.
--- glances/plugins/glances_quicklook.py.orig	2022-07-28 16:12:29.000000000 +0000
+++ glances/plugins/glances_quicklook.py
@@ -64,10 +64,12 @@ class Plugin(GlancesPlugin):
             # Get additional information
             cpu_info = cpu_percent.get_info()
             stats['cpu_name'] = cpu_info['cpu_name']
-            stats['cpu_hz_current'] = (
-                self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
-            )
-            stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
+            if 'cpu_hz_current' in cpu_info:
+                stats['cpu_hz_current'] = (
+                    self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
+                )
+            if 'cpu_hz' in cpu_info:
+                stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
 
         elif self.input_method == 'snmp':
             # Not available
