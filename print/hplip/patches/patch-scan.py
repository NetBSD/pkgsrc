$NetBSD: patch-scan.py,v 1.3 2015/06/14 21:50:53 schnoebe Exp $

Try to work better with multiple versions of Python

--- scan.py.orig	2013-03-08 07:15:32.000000000 +0000
+++ scan.py
@@ -688,7 +688,7 @@ try:
         scan_area = (brx - tlx) * (bry - tly) # mm^2
 
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % (valid_res,))
+        log.debug("Device supported resolutions %s" % ', ' . join([str(x) for x in valid_res]))
         if 0 in valid_res: #min-max range in tuple
            if res < valid_res[0] or res > valid_res[1]:
              log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
