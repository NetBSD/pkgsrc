$NetBSD: patch-SRC_pstrord.f,v 1.1 2022/08/25 22:58:01 thor Exp $

upstream gcc10 build fix, commit a0f76fc0c1c16646875b454b7d6f8d9d17726b5a

--- SRC/pstrord.f.orig	2021-10-12 19:09:12.000000000 +0000
+++ SRC/pstrord.f
@@ -487,10 +487,10 @@
             MMAX( 1 ) = M
             MMIN( 1 ) = M
             IF( NPROCS.GT.1 )
-     $         CALL IGAMX2D( ICTXT, 'All', TOP, 1, 1, MMAX, 1, -1,
+     $         CALL IGAMX2D( ICTXT, 'All', TOP, 1, 1, MMAX( 1 ), 1, -1,
      $              -1, -1, -1, -1 )
             IF( NPROCS.GT.1 )
-     $         CALL IGAMN2D( ICTXT, 'All', TOP, 1, 1, MMIN, 1, -1,
+     $         CALL IGAMN2D( ICTXT, 'All', TOP, 1, 1, MMIN( 1 ), 1, -1,
      $              -1, -1, -1, -1 )
             IF( MMAX( 1 ).GT.MMIN( 1 ) ) THEN
                M = MMAX( 1 )
