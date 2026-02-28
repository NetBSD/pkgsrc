$NetBSD: patch-SRC_DEPRECATED_sgeqpf.f,v 1.1 2026/02/28 08:38:00 thor Exp $

Fix bogus symbols due to expanded ILP64 macros, lifted from FreeBSD.
This is fixed upstream, just missing a release.

--- SRC/DEPRECATED/sgeqpf.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/sgeqpf.f
@@ -218,8 +218,8 @@
          MA = MIN( ITEMP, M )
          CALL SGEQR2( M, MA, A, LDA, TAU, WORK, INFO )
          IF( MA.LT.N ) THEN
-            CALL SORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA, TAU,
-     $                   A( 1, MA+1 ), LDA, WORK, INFO )
+            CALL SORM2R( 'Left', 'Transpose', M, N-MA, MA, A, LDA,
+     $                    TAU, A( 1, MA+1 ), LDA, WORK, INFO )
          END IF
       END IF
 *
