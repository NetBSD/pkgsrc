$NetBSD: patch-glances_plugins_glances__quicklook.py,v 1.1 2021/07/16 04:24:16 fox Exp $

It seems cpu_hz_current and cpu_hz is not available in NetBSD, so add additional
check to see if the key exists.
--- glances/plugins/glances_quicklook.py.orig	2021-07-10 07:09:24.000000000 +0000
+++ glances/plugins/glances_quicklook.py
@@ -82,8 +82,10 @@ class Plugin(GlancesPlugin):
             # Get additional information
             cpu_info = cpu_percent.get_info()
             stats['cpu_name'] = cpu_info['cpu_name']
-            stats['cpu_hz_current'] = self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
-            stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
+            if 'cpu_hz_current' in cpu_info:
+                stats['cpu_hz_current'] = self._mhz_to_hz(cpu_info['cpu_hz_current']) if cpu_info['cpu_hz_current'] is not None else None
+            if 'cpu_hz' in cpu_info:
+                stats['cpu_hz'] = self._mhz_to_hz(cpu_info['cpu_hz']) if cpu_info['cpu_hz'] is not None else None
 
         elif self.input_method == 'snmp':
             # Not available
@@ -193,4 +195,4 @@ class Plugin(GlancesPlugin):
 
     def _mhz_to_hz(self, hz):
         """Convert Mhz to Hz."""
-        return hz * 1000000.0
\ No newline at end of file
+        return hz * 1000000.0
