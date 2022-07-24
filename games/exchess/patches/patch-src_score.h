$NetBSD: patch-src_score.h,v 1.1 2022/07/24 21:26:30 he Exp $

The piece_sq table depends on signed chars which isn't
the default on NetBSD/powerpc, so make that explicit.

--- src/score.h.orig	2017-02-04 14:23:32.000000000 +0000
+++ src/score.h
@@ -96,7 +96,7 @@ char attack_scale[16] = { 0, 1, 2, 4, 9,
 // stage 3 = ending
 
 
-char piece_sq[4][7][64] = {    // note values cannot exceed +127 or -127!
+signed char piece_sq[4][7][64] = {    // note values cannot exceed +127 or -127!
 
 // Reading these is a little tricky.  These tables
 // are set up to look like a chess board from white's
