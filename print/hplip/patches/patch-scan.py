$NetBSD: patch-scan.py,v 1.1.1.1 2012/05/18 03:03:22 schnoebe Exp $

Try to work better with multiple versions of Python

--- scan.py.orig	2011-10-02 03:06:19.000000000 +0000
+++ scan.py
@@ -620,7 +620,7 @@ try:
         scan_px = scan_area * res * res / 645.16 # res is in DPI
         
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % (valid_res,))
+        log.debug("Device supported resolutions %s" % ', '.join([str(x) for x in valid_res]))
         if 0 in valid_res: #min-max range in tuple
            if res < valid_res[0] or res > valid_res[1]:
              log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
@@ -633,6 +633,7 @@ try:
           if res not in valid_res:
             log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
             log.warn("Valid resolutions are %s dpi." % ', '.join([str(x) for x in valid_res]))
+	    r = res
             res = valid_res[0]
             min_dist = sys.maxint
             for x in valid_res:
