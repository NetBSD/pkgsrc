$NetBSD: patch-src_player_meta.h,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2015-4695 - meta.h in libwmf 0.2.8.4 allows remote attackers to cause a
denial of service (out-of-bounds read) via a crafted WMF file.
CVE-2015-4696 - Use-after-free vulnerability in libwmf 0.2.8.4 allows remote
attackers to cause a denial of service (crash) via a crafted WMF file to the (1)
wmf2gd or (2) wmf2eps command.

--- src/player/meta.h.orig	2005-07-27 20:35:06.000000000 +0000
+++ src/player/meta.h
@@ -1565,7 +1565,7 @@ static int meta_rgn_create (wmfAPI* API,
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
@@ -2142,7 +2142,7 @@ static int meta_dib_brush (wmfAPI* API,w
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
@@ -2585,6 +2585,8 @@ static int meta_dc_restore (wmfAPI* API,
 			polyrect.BR[i] = clip->rects[i].BR;
 		}
 
+		if (FR->region_clip) FR->region_clip (API,&polyrect);
+
 		wmf_free (API,polyrect.TL);
 		wmf_free (API,polyrect.BR);
 	}
@@ -2593,9 +2595,9 @@ static int meta_dc_restore (wmfAPI* API,
 		polyrect.BR = 0;
 
 		polyrect.count = 0;
-	}
 
-	if (FR->region_clip) FR->region_clip (API,&polyrect);
+		if (FR->region_clip) FR->region_clip (API,&polyrect);
+	}
 
 	return (changed);
 }
@@ -3067,7 +3069,7 @@ static int meta_pen_create (wmfAPI* API,
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
@@ -3181,7 +3183,7 @@ static int meta_brush_create (wmfAPI* AP
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
@@ -3288,7 +3290,7 @@ static int meta_font_create (wmfAPI* API
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
@@ -3396,7 +3398,7 @@ static int meta_palette_create (wmfAPI* 
 	objects = P->objects;
 
 	i = 0;
-	while (objects[i].type && (i < NUM_OBJECTS (API))) i++;
+	while ((i < NUM_OBJECTS (API)) && objects[i].type) i++;
 
 	if (i == NUM_OBJECTS (API))
 	{	WMF_ERROR (API,"Object out of range!");
