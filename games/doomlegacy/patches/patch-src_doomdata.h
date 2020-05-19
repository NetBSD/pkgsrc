$NetBSD: patch-src_doomdata.h,v 1.1 2020/05/19 11:20:16 micha Exp $

Refer to subsectors with 32-Bit values (required for extended nodes).
Upstream feature request:
https://sourceforge.net/p/doomlegacy/feature-requests/95/

--- src/doomdata.h.orig	2020-04-20 10:32:30.000000000 +0000
+++ src/doomdata.h
@@ -203,7 +203,8 @@ typedef struct
 // BSP node structure.
 
 // Indicate a leaf.
-#define NF_SUBSECTOR    0x8000
+// [MB] 2020-04-22: Changed to 32-Bit for extended nodes
+#define NF_SUBSECTOR    0x80000000
 
 // WAD lump structure
 typedef struct
@@ -218,7 +219,8 @@ typedef struct
   // clip against view frustum.
   int16_t       bbox[2][4];
 
-  // If NF_SUBSECTOR its a subsector,
+  // [MB] 2020-04-22: NF_SUBSECTOR no longer matches here!
+  // If MSB is set it's a subsector,
   // else it's a node of another subtree.
   uint16_t      children[2];
 
