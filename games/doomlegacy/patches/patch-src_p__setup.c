$NetBSD: patch-src_p__setup.c,v 1.2 2020/05/20 16:04:12 micha Exp $

Add support for DeeP and ZDoom extended nodes.
Upstream feature request:
https://sourceforge.net/p/doomlegacy/feature-requests/95/

Add support to internally create blockmap.
https://sourceforge.net/p/doomlegacy/feature-requests/96/

--- src/p_setup.c.orig	2020-05-11 09:40:34.000000000 +0000
+++ src/p_setup.c
@@ -150,6 +150,9 @@
 //-----------------------------------------------------------------------------
 
 #include "doomincl.h"
+#include "m_argv.h"      // [MB] 2020-05-13: To check for "-blockmap" option
+#include "p_blockmap.h"  // [MB] 2020-05-13: For internal blockmap creation
+#include "p_extnodes.h"  // [MB] 2020-04-21: For import of extended nodes
 #include "p_local.h"
 #include "p_tick.h"
   // think
@@ -251,14 +254,15 @@ typedef struct mapdata_s {
 // Created from axis aligned bounding box of the map, a rectangular array of
 // blocks of size ...
 // Used to speed up collision detection by spatial subdivision in 2D.
+// [MB] 2020-05-13: Fix comments (blockmapindex points to offset part of lump)
 //
 // Blockmap size.
 int             bmapwidth;
 int             bmapheight;     // size in mapblocks
 
-uint32_t *      blockmapindex;       // for large maps, wad is 16bit
-// offsets in blockmap are from here
-uint32_t *      blockmaphead; // Big blockmap, SSNTails
+uint32_t *      blockmaphead;   // Big blockmap, SSNTails
+uint32_t *      blockmapindex;  // For large maps, wad is 16bit
+                                // (offsets in blockmap are from here)
 
 // origin of block map
 fixed_t         bmaporgx;
@@ -282,6 +286,7 @@ mapthing_t  *   playerstarts[MAXPLAYERS]
 
 #if 0
 // [WDJ] Checks from PrBoom.
+// [MB] 2020-04-21: Used the woof code from p_extnodes.c instead
 
 // figgi 08/21/00 -- constants and globals for glBsp support
 #define gNd2  0x32644E67
@@ -793,7 +798,22 @@ void P_LoadNodes (int lump)
         no->dy = LE_SWAP16(mn->dy)<<FRACBITS;
         for (j=0 ; j<2 ; j++)
         {
-            no->children[j] = (uint16_t)( LE_SWAP16(mn->children[j]) );
+            no->children[j] = (uint16_t) ( LE_SWAP16(mn->children[j]) );
+
+            // [MB] 2020-04-21: Changed for extended nodes
+            if (no->children[j] == 0xFFFF)
+                no->children[j] = -1;
+            else
+            if (no->children[j] & 0x8000)
+            {
+                no->children[j] &= ~0x8000;
+
+                 if (no->children[j] >= numsubsectors)
+                    no->children[j] = 0;
+
+                 no->children[j] |= NF_SUBSECTOR;
+            }
+
             for (k=0 ; k<4 ; k++)
                 no->bbox[j][k] = LE_SWAP16(mn->bbox[j][k])<<FRACBITS;
         }
@@ -1840,6 +1860,7 @@ boolean P_SetupLevel (int      to_episod
     const char  *errstr;
     char  *sl_mapname = NULL;
     int   i;
+    mapformat_t mapformat;
 
     GenPrintf( (verbose? (EMSG_ver|EMSG_now) : (EMSG_console|EMSG_now)),
                "Setup Level\n" );
@@ -1985,18 +2006,69 @@ boolean P_SetupLevel (int      to_episod
         goto load_reject;
     }
 
-    // note: most of this ordering is important
-    P_LoadBlockMap (level_lumpnum+ML_BLOCKMAP);
-    P_LoadVertexes (level_lumpnum+ML_VERTEXES);
-    P_LoadSectors  (level_lumpnum+ML_SECTORS);
-    P_LoadSideDefs (level_lumpnum+ML_SIDEDEFS);
-
-    P_LoadLineDefs (level_lumpnum+ML_LINEDEFS);
-    P_LoadSideDefs2(level_lumpnum+ML_SIDEDEFS);
-    P_LoadLineDefs2();
-    P_LoadSubsectors (level_lumpnum+ML_SSECTORS);
-    P_LoadNodes (level_lumpnum+ML_NODES);
-    P_LoadSegs (level_lumpnum+ML_SEGS);
+    // [MB] 2020-04-21: Node format check from woof (p_extnodes.c)
+    mapformat = P_CheckMapFormat(level_lumpnum);
+    switch (mapformat)
+    {
+    case MFMT_DOOMBSP:
+        GenPrintf(EMSG_info, "Node format: Regular\n" );
+        break;
+    case MFMT_DEEPBSP:
+        GenPrintf(EMSG_info, "Node format: DeeP V4 extended\n" );
+        break;
+    case MFMT_ZDBSPX:
+        GenPrintf(EMSG_info, "Node format: ZDoom extended\n" );
+        break;
+#if HAVE_ZLIB
+    case MFMT_ZDBSPZ:
+        GenPrintf(EMSG_info, "Node format: ZDoom extended (compressed)\n" );
+        break;
+#endif  // HAVE_ZLIB
+    default:
+        I_Error( "P_SetupLevel: Node format not supported\n" );
+        break;
+    }
+
+    {
+        // [MB] 2020-05-13: Added option to internally create blockmap
+        boolean create_blockmap = M_CheckParm("-blockmap");
+
+        // note: most of this ordering is important
+        if (!create_blockmap)
+            P_LoadBlockMap (level_lumpnum+ML_BLOCKMAP);
+        P_LoadVertexes (level_lumpnum+ML_VERTEXES);
+        P_LoadSectors  (level_lumpnum+ML_SECTORS);
+        P_LoadSideDefs (level_lumpnum+ML_SIDEDEFS);
+        P_LoadLineDefs (level_lumpnum+ML_LINEDEFS);
+        P_LoadSideDefs2(level_lumpnum+ML_SIDEDEFS);
+        P_LoadLineDefs2();
+        // [MB] 2020-05-13: Internally create blockmap on request
+        if (create_blockmap)
+        {
+            GenPrintf(EMSG_info, "Ignore BLOCKMAP lump, create blockmap\n" );
+            P_CreateBlockMap ();
+        }
+    }
+
+    // [MB] 2020-04-21: Hook in code imported from woof 1.2.0 (p_extnodes.c)
+    if (mapformat == MFMT_ZDBSPX || mapformat == MFMT_ZDBSPZ)
+    {
+        P_LoadNodes_ZDBSP (level_lumpnum+ML_NODES, mapformat == MFMT_ZDBSPZ);
+    }
+    else if (mapformat == MFMT_DEEPBSP)
+    {
+        P_LoadSubsectors_DeePBSP (level_lumpnum+ML_SSECTORS);
+        P_LoadNodes_DeePBSP (level_lumpnum+ML_NODES);
+        P_LoadSegs_DeePBSP (level_lumpnum+ML_SEGS);
+    }
+    // [MB] 2020-04-21: This is the former DooM Legacy code
+    else
+    {
+        P_LoadSubsectors (level_lumpnum+ML_SSECTORS);
+        P_LoadNodes (level_lumpnum+ML_NODES);
+        P_LoadSegs (level_lumpnum+ML_SEGS);
+    }
+
     rejectmatrix = W_CacheLumpNum (level_lumpnum+ML_REJECT,PU_LEVEL);
     P_GroupLines ();
 
