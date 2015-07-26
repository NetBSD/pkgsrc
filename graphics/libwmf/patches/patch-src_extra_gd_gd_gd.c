$NetBSD: patch-src_extra_gd_gd_gd.c,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2009-3546 - The _gdGetColors function in gd_gd.c in PHP 5.2.11 and 5.3.x
before 5.3.1, and the GD Graphics Library 2.x, does not properly verify a
certain colorsTotal structure member, which might allow remote attackers to
conduct buffer overflow or buffer over-read attacks via a crafted GD file.

--- src/extra/gd/gd_gd.c.orig	2005-07-27 20:35:05.000000000 +0000
+++ src/extra/gd/gd_gd.c
@@ -37,6 +37,10 @@ _gdGetColors (gdIOCtx * in, gdImagePtr i
 	    {
 	      goto fail1;
 	    }
+	  if (&im->colorsTotal > gdMaxColors)
+	    {
+	      goto fail1;
+	    }
 	}
       /* Int to accommodate truecolor single-color transparency */
       if (!gdGetInt (&im->transparent, in))
