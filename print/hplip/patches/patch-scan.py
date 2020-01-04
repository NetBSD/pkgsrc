$NetBSD: patch-scan.py,v 1.4 2020/01/04 04:24:12 khorben Exp $

Try to work better with multiple versions of Python

--- scan.py.orig	2019-12-10 05:00:36.000000000 +0000
+++ scan.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python3.7
 # -*- coding: utf-8 -*-
 #
 # (c) Copyright 2003-2015 HP Development Company, L.P.
@@ -1028,7 +1028,7 @@ try:
         scan_area = (brx - tlx) * (bry - tly) # mm^2
 
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % (valid_res,))
+        log.debug("Device supported resolutions %s" % ', ' . join([str(x) for x in valid_res]))
         if 0 in valid_res: #min-max range in tuple
            if res < valid_res[0] or res > valid_res[1]:
              log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
@@ -1911,7 +1911,7 @@ try:
             elif d == 'print':
                 hp_print = utils.which("hp-print", True)
                 if not hp_print:
-                    hp_print = 'python ./print.py'
+                    hp_print = '/usr/pkg/bin/python3.7 ./print.py'
                  
                 if dest_printer is not None:
                    cmd = '%s -p %s %s &' % (hp_print, dest_printer, output)
