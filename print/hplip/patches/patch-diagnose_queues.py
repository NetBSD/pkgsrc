$NetBSD: patch-diagnose_queues.py,v 1.3 2020/01/04 04:24:12 khorben Exp $

Correct the spelling on the module name.

--- diagnose_queues.py.orig	2019-12-10 05:00:36.000000000 +0000
+++ diagnose_queues.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python3.7
 # -*- coding: utf-8 -*-
 #
 # (c) Copyright 2011-2015 HP Development Company, L.P.
@@ -22,7 +22,7 @@
 from __future__ import print_function
 __version__ = '1.1'
 __title__ = 'AutoConfig Utility to check queues configuration'
-__mod__ = 'hp-daignose-queues'
+__mod__ = 'hp-diagnose-queues'
 __doc__ = """Auto config utility for HPLIP supported multifunction Devices to diagnose queues configuration."""
 
 # Std Lib
