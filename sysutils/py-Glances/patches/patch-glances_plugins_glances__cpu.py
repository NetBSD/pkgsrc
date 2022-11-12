$NetBSD: patch-glances_plugins_glances__cpu.py,v 1.3 2022/11/12 06:19:26 fox Exp $

Disable system call counts in BSD.
--- glances/plugins/glances_cpu.py.orig	2022-11-03 14:30:13.000000000 +0000
+++ glances/plugins/glances_cpu.py
@@ -12,7 +12,7 @@
 from glances.timer import getTimeSinceLastUpdate
 from glances.compat import iterkeys
 from glances.cpu_percent import cpu_percent
-from glances.globals import LINUX, WINDOWS, SUNOS
+from glances.globals import LINUX, WINDOWS, SUNOS, BSD
 from glances.plugins.glances_core import Plugin as CorePlugin
 from glances.plugins.glances_plugin import GlancesPlugin
 
@@ -386,7 +386,7 @@ class Plugin(GlancesPlugin):
         # Steal CPU usage
         ret.extend(self.curse_add_stat('steal', width=14, header='  '))
         # syscalls: number of system calls since boot. Always set to 0 on Linux. (do not display)
-        if not LINUX:
+        if not LINUX and not BSD:
             ret.extend(self.curse_add_stat('syscalls', width=15, header='  '))
 
         # Return the message with decoration
