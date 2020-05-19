$NetBSD: patch-src_r__defs.h,v 1.1 2020/05/19 11:20:16 micha Exp $

Refer to segments and subsectors with 32-Bit values.
Upstream feature request:
https://sourceforge.net/p/doomlegacy/feature-requests/95/

--- src/r_defs.h.orig	2020-04-20 10:32:32.000000000 +0000
+++ src/r_defs.h
@@ -130,8 +130,7 @@
 
 
 // Max index (or -1). Used in line_t::sidenum and maplinedef_t::sidenum.
-#define NULL_INDEX   0xFFFF
-
+#define NULL_INDEX   UINT16_C(0xFFFF)
 
 // Silhouette, needed for clipping Segs (mainly)
 // and sprites representing things.
@@ -566,9 +565,9 @@ typedef struct subsector_s
 {
     sector_t*   sector;   // (ref) part of this sector, from segs->sector of firstline
     // numlines and firstline are from the subsectors lump (nodebuilder)
-    // [WDJ] some wad may be large enough to overflow signed short.
-    unsigned short  numlines;   // number of segs in this subsector
-    unsigned short  firstline;  // index into segs lump (loaded from wad)
+    // [MB] 2020-04-22: Changed to 32-Bit for extended nodes
+    uint32_t  numlines;   // number of segs in this subsector
+    uint32_t  firstline;  // index into segs lump (loaded from wad)
     // floorsplat_t list
     void*       splats;
     //Hurdler: added for optimized mlook in hw mode
@@ -790,7 +789,9 @@ typedef struct
 
     // If NF_SUBSECTOR is set then rest of it is a subsector index,
     // otherwise it is another node index.
-    uint16_t    children[2];
+    // [MB] 2020-04-22: Changed to 32-Bit for extended nodes
+    //      Use int to match rest of the code (should be uint32_t)
+    int         children[2];
         // children[0]= right
         // children[1]= left
 } node_t;
