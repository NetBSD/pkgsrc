$NetBSD: patch-diagnose_queues.py,v 1.4 2022/03/13 05:46:55 gutteridge Exp $

Correct the spelling on the module name.

--- diagnose_queues.py.orig	2019-12-10 05:00:36.000000000 +0000
+++ diagnose_queues.py
@@ -22,7 +22,7 @@
 from __future__ import print_function
 __version__ = '1.1'
 __title__ = 'AutoConfig Utility to check queues configuration'
-__mod__ = 'hp-daignose-queues'
+__mod__ = 'hp-diagnose-queues'
 __doc__ = """Auto config utility for HPLIP supported multifunction Devices to diagnose queues configuration."""
 
 # Std Lib
