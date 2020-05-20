$NetBSD: patch-src_p__local.h,v 1.2 2020/05/20 16:04:12 micha Exp $

Add support to internally create blockmap.
https://sourceforge.net/p/doomlegacy/feature-requests/96/

--- src/p_local.h.orig	2020-05-11 09:40:33.000000000 +0000
+++ src/p_local.h
@@ -379,8 +379,9 @@ void P_ApplyTorque(mobj_t *mo);
 extern byte*            rejectmatrix;   // for fast sight rejection
 // Read wad blockmap using int16_t wadblockmaplump[].
 // Expand from 16bit wad to internal 32bit blockmap.
-extern uint32_t*        blockmaphead;   // offsets in blockmap are from here
-extern uint32_t*        blockmapindex;  // Big blockmap, SSNTails
+// [MB] 2020-05-13: Fix comments (blockmapindex points to offset part of lump)
+extern uint32_t*        blockmaphead;   // Big blockmap, SSNTails
+extern uint32_t*        blockmapindex;  // offsets in blockmap are from here
 extern int              bmapwidth;
 extern int              bmapheight;     // in mapblocks
 extern fixed_t          bmaporgx;
