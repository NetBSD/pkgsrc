$NetBSD: patch-scan.py,v 1.5 2022/03/13 05:46:55 gutteridge Exp $

Try to work better with multiple versions of Python

--- scan.py.orig	2019-12-10 05:00:36.000000000 +0000
+++ scan.py
@@ -1028,7 +1028,7 @@ try:
         scan_area = (brx - tlx) * (bry - tly) # mm^2
 
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % (valid_res,))
+        log.debug("Device supported resolutions %s" % ', ' . join([str(x) for x in valid_res]))
         if 0 in valid_res: #min-max range in tuple
            if res < valid_res[0] or res > valid_res[1]:
              log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
