$NetBSD: patch-ext_gd_libgd_gdxpm.c,v 1.1 2014/05/11 11:20:47 he Exp $

Patch to fix CVE-2014-2497, taken from
https://bugs.php.net/patch-display.php?bug_id=66901

--- ext/gd/libgd/gdxpm.c.orig	2014-04-29 08:04:30.000000000 +0000
+++ ext/gd/libgd/gdxpm.c
@@ -39,6 +39,13 @@ gdImagePtr gdImageCreateFromXpm (char *f
 	number = image.ncolors;
 	colors = (int *) safe_emalloc(number, sizeof(int), 0);
 	for (i = 0; i < number; i++) {
+		if (!image.colorTable[i].c_color)
+		{
+			/* unsupported color key or color key not defined */
+			gdImageDestroy(im);
+			im = 0;
+			goto done;
+		}
 		switch (strlen (image.colorTable[i].c_color)) {
 			case 4:
 				buf[1] = '\0';
@@ -125,8 +132,8 @@ gdImagePtr gdImageCreateFromXpm (char *f
 		}
 	}
 
-	gdFree(colors);
  done:
+	gdFree(colors);
 	XpmFreeXpmImage(&image);
 	XpmFreeXpmInfo(&info);
 	return im;
