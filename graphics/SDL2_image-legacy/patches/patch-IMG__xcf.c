$NetBSD: patch-IMG__xcf.c,v 1.1 2024/05/06 18:05:32 nia Exp $

Fix various security issues,

CVE-2017-2887
CVE-2018-3838
CVE-2018-3839
CVE-2017-14448
CVE-2017-14449

Taken from Ubuntu Linux.

--- IMG_xcf.c.orig	2016-01-03 05:52:28.000000000 +0000
+++ IMG_xcf.c
@@ -251,6 +251,7 @@ static Uint32 Swap32 (Uint32 v) {
 }
 
 static void xcf_read_property (SDL_RWops * src, xcf_prop * prop) {
+  Uint32 len;
   prop->id = SDL_ReadBE32 (src);
   prop->length = SDL_ReadBE32 (src);
 
@@ -274,7 +275,12 @@ static void xcf_read_property (SDL_RWops
     break;
   case PROP_COMPRESSION:
   case PROP_COLOR:
-    SDL_RWread (src, &prop->data, prop->length, 1);
+    if (prop->length > sizeof(prop->data)) {
+        len = sizeof(prop->data);
+    } else {
+        len = prop->length;
+    }
+    SDL_RWread(src, &prop->data, len, 1);
     break;
   case PROP_VISIBLE:
     prop->data.visible = SDL_ReadBE32 (src);
@@ -468,10 +474,14 @@ static unsigned char * load_xcf_tile_rle
   int i, size, count, j, length;
   unsigned char val;
 
+  if (len == 0) {  /* probably bogus data. */
+    return NULL;
+  }
+
   t = load = (unsigned char *) SDL_malloc (len);
   reallen = SDL_RWread (src, t, 1, len);
 
-  data = (unsigned char *) SDL_malloc (x*y*bpp);
+  data = (unsigned char *) SDL_calloc (1, x*y*bpp);
   for (i = 0; i < bpp; i++) {
     d    = data + i;
     size = x*y;
@@ -488,6 +498,12 @@ static unsigned char * load_xcf_tile_rle
       t += 2;
     }
 
+        if (((size_t) (t - load) + length) >= len) {
+          break;  /* bogus data */
+        } else if (length > size) {
+          break;  /* bogus data */
+        }
+
     count += length;
     size -= length;
 
@@ -503,6 +519,12 @@ static unsigned char * load_xcf_tile_rle
       t += 2;
     }
 
+        if (((size_t) (t - load)) >= len) {
+          break;  /* bogus data */
+        } else if (length > size) {
+          break;  /* bogus data */
+        }
+
     count += length;
     size -= length;
 
@@ -514,6 +536,11 @@ static unsigned char * load_xcf_tile_rle
     }
       }
     }
+
+    if (size > 0) {
+      break;  /* just drop out, untouched data initialized to zero. */
+    }
+
   }
 
   SDL_free (load);
@@ -558,6 +585,18 @@ static int do_layer_surface (SDL_Surface
   SDL_RWseek (src, layer->hierarchy_file_offset, RW_SEEK_SET);
   hierarchy = read_xcf_hierarchy (src);
 
+  if (hierarchy->bpp > 4) {  /* unsupported. */
+    fprintf(stderr, "Unknown Gimp image bpp (%u)\n", (unsigned int) hierarchy->bpp);
+    free_xcf_hierarchy(hierarchy);
+    return 1;
+  }
+
+  if ((hierarchy->width > 20000) || (hierarchy->height > 20000)) {  /* arbitrary limit to avoid integer overflow. */
+    fprintf(stderr, "Gimp image too large (%ux%u)\n", (unsigned int) hierarchy->width, (unsigned int) hierarchy->height);
+    free_xcf_hierarchy(hierarchy);
+    return 1;
+  }
+
   level = NULL;
   for (i = 0; hierarchy->level_file_offsets [i]; i++) {
     SDL_RWseek (src, hierarchy->level_file_offsets [i], RW_SEEK_SET);
@@ -584,6 +623,16 @@ static int do_layer_surface (SDL_Surface
        ox, oy);
       }
 
+      if (!tile) {
+          if (hierarchy) {
+              free_xcf_hierarchy(hierarchy);
+          }
+          if (level) {
+              free_xcf_level(level);
+          }
+          return 1;
+      }
+
       p8  = tile;
       p16 = (Uint16 *) p8;
       p   = (Uint32 *) p8;
@@ -627,9 +676,6 @@ static int do_layer_surface (SDL_Surface
         fprintf (stderr, "Unknown Gimp image type (%d)\n", head->image_type);
         if (hierarchy)
         {
-          if (hierarchy->level_file_offsets)
-            SDL_free(hierarchy->level_file_offsets);
-         
           free_xcf_hierarchy(hierarchy);
         }
         if (level)     
