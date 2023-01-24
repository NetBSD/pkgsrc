$NetBSD: patch-src_cairo-arc.c,v 1.1 2023/01/24 10:10:23 wiz Exp $

https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/155
fixing
https://gitlab.freedesktop.org/cairo/cairo/-/issues/353
which is for CVE-2019-6461.

--- src/cairo-arc.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ src/cairo-arc.c
@@ -90,16 +90,18 @@ _arc_max_angle_for_tolerance_normalized 
 	{ M_PI / 11.0,  9.81410988043554039085e-09 },
     };
     int table_size = ARRAY_LENGTH (table);
+    const int max_segments = 1000; /* this value is chosen arbitrarily. this gives an error of about 1.74909e-20 */
 
     for (i = 0; i < table_size; i++)
 	if (table[i].error < tolerance)
 	    return table[i].angle;
 
     ++i;
+
     do {
 	angle = M_PI / i++;
 	error = _arc_error_normalized (angle);
-    } while (error > tolerance);
+    } while (error > tolerance && i < max_segments);
 
     return angle;
 }
