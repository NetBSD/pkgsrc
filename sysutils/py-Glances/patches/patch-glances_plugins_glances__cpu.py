$NetBSD: patch-glances_plugins_glances__cpu.py,v 1.2 2022/08/08 09:28:06 fox Exp $

Disable system call counts in BSD.
--- glances/plugins/glances_cpu.py.orig	2022-07-28 16:12:29.000000000 +0000
+++ glances/plugins/glances_cpu.py
@@ -13,7 +13,7 @@ from glances.logger import logger
 from glances.timer import getTimeSinceLastUpdate
 from glances.compat import iterkeys
 from glances.cpu_percent import cpu_percent
-from glances.globals import LINUX
+from glances.globals import LINUX, BSD
 from glances.plugins.glances_core import Plugin as CorePlugin
 from glances.plugins.glances_plugin import GlancesPlugin
 
@@ -366,7 +366,7 @@ class Plugin(GlancesPlugin):
         # Steal CPU usage
         ret.extend(self.curse_add_stat('steal', width=14, header='  '))
         # syscalls: number of system calls since boot. Always set to 0 on Linux. (do not display)
-        if not LINUX:
+        if not LINUX and not BSD:
             ret.extend(self.curse_add_stat('syscalls', width=15, header='  '))
 
         # Return the message with decoration
