$NetBSD: patch-src_extra_gd_gd.c,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2007-3472 - Integer overflow in gdImageCreateTrueColor function.
CVE-2007-3473 - The gdImageCreateXbm function in the GD Graphics Library (libgd)
before 2.0.35 allows user-assisted remote attackers to cause a denial of service
(crash) via unspecified vectors involving a gdImageCreate failure.
CVE-2007-3477 - The (a) imagearc and (b) imagefilledarc functions in GD Graphics
Library (libgd) before 2.0.35 allow attackers to cause a denial of service (CPU
consumption) via a large (1) start or (2) end angle degree value.

--- src/extra/gd/gd.c.orig	2005-07-27 20:35:05.000000000 +0000
+++ src/extra/gd/gd.c
@@ -106,6 +106,18 @@ gdImageCreateTrueColor (int sx, int sy)
   gdImagePtr im;
   unsigned long cpa_size;
 
+  if (overflow2(sx, sy)) {
+    return NULL;
+  }
+
+  if (overflow2(sizeof (int *), sy)) {
+    return NULL;
+  }
+
+  if (overflow2(sizeof(int), sx)) {
+    return NULL;
+  }
+
   im = (gdImage *) gdMalloc (sizeof (gdImage));
   if (im == 0) return 0;
   memset (im, 0, sizeof (gdImage));
@@ -1321,10 +1333,31 @@ gdImageFilledArc (gdImagePtr im, int cx,
   int w2, h2;
   w2 = w / 2;
   h2 = h / 2;
-  while (e < s)
-    {
-      e += 360;
-    }
+
+  if ((s % 360)  == (e % 360)) {
+         s = 0; e = 360;
+  } else {
+         if (s > 360) {
+                 s = s % 360;
+         }
+
+         if (e > 360) {
+                 e = e % 360;
+         }
+
+         while (s < 0) {
+                 s += 360;
+         }
+
+         while (e < s) {
+                 e += 360;
+         }
+
+         if (s == e) {
+                 s = 0; e = 360;
+         }
+  }
+
   for (i = s; (i <= e); i++)
     {
       int x, y;
@@ -2169,6 +2202,10 @@ gdImageCreateFromXbm (FILE * fd)
     }
   bytes = (w * h / 8) + 1;
   im = gdImageCreate (w, h);
+  if (!im) {
+    return 0;
+  }
+
   gdImageColorAllocate (im, 255, 255, 255);
   gdImageColorAllocate (im, 0, 0, 0);
   x = 0;
