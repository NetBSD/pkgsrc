$NetBSD: patch-scan.py,v 1.2 2013/04/12 03:47:30 schnoebe Exp $

Try to work better with multiple versions of Python

--- scan.py.orig	2013-03-08 07:15:32.000000000 +0000
+++ scan.py
@@ -665,7 +665,7 @@ try:
         scan_area = (brx - tlx) * (bry - tly) # mm^2
 
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % (valid_res,))
+        log.debug("Device supported resolutions %s" % ', ' . join([str(x) for x in valid_res]))
         if 0 in valid_res: #min-max range in tuple
            if res < valid_res[0] or res > valid_res[1]:
              log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
@@ -678,6 +678,7 @@ try:
           if res not in valid_res:
             log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
             log.warn("Valid resolutions are %s dpi." % ', '.join([str(x) for x in valid_res]))
+	    r = res
             res = valid_res[0]
             min_dist = sys.maxint
             for x in valid_res:
