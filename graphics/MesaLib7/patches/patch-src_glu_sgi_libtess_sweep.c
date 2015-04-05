$NetBSD: patch-src_glu_sgi_libtess_sweep.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

Fixes segfaults and crashes in applications using libGLU.
--- src/glu/sgi/libtess/sweep.c.orig	2010-10-05 16:56:51.000000000 +0000
+++ src/glu/sgi/libtess/sweep.c
@@ -546,7 +546,9 @@ static int CheckForRightSplice( GLUtesse
     if( EdgeSign( eUp->Dst, eLo->Org, eUp->Org ) < 0 ) return FALSE;
 
     /* eLo->Org appears to be above eUp, so splice eLo->Org into eUp */
-    RegionAbove(regUp)->dirty = regUp->dirty = TRUE;
+    if (RegionAbove(regUp))
+        RegionAbove(regUp)->dirty = TRUE;
+    regUp->dirty = TRUE;
     if (__gl_meshSplitEdge( eUp->Sym ) == NULL) longjmp(tess->env,1);
     if ( !__gl_meshSplice( eLo->Oprev, eUp ) ) longjmp(tess->env,1);
   }
@@ -584,7 +586,9 @@ static int CheckForLeftSplice( GLUtessel
     if( EdgeSign( eUp->Dst, eLo->Dst, eUp->Org ) < 0 ) return FALSE;
 
     /* eLo->Dst is above eUp, so splice eLo->Dst into eUp */
-    RegionAbove(regUp)->dirty = regUp->dirty = TRUE;
+    if (RegionAbove(regUp))
+        RegionAbove(regUp)->dirty = TRUE;
+    regUp->dirty = TRUE;
     e = __gl_meshSplitEdge( eUp );
     if (e == NULL) longjmp(tess->env,1);
     if ( !__gl_meshSplice( eLo->Sym, e ) ) longjmp(tess->env,1);
@@ -718,7 +722,9 @@ static int CheckForIntersect( GLUtessela
      * (and wait for ConnectRightVertex to splice it appropriately).
      */
     if( EdgeSign( dstUp, tess->event, &isect ) >= 0 ) {
-      RegionAbove(regUp)->dirty = regUp->dirty = TRUE;
+      if (RegionAbove(regUp))
+          RegionAbove(regUp)->dirty = TRUE;
+      regUp->dirty = TRUE;
       if (__gl_meshSplitEdge( eUp->Sym ) == NULL) longjmp(tess->env,1);
       eUp->Org->s = tess->event->s;
       eUp->Org->t = tess->event->t;
@@ -753,7 +759,9 @@ static int CheckForIntersect( GLUtessela
      longjmp(tess->env,1);
   }
   GetIntersectData( tess, eUp->Org, orgUp, dstUp, orgLo, dstLo );
-  RegionAbove(regUp)->dirty = regUp->dirty = regLo->dirty = TRUE;
+  if (RegionAbove(regUp))
+      RegionAbove(regUp)->dirty = TRUE;
+  regUp->dirty = regLo->dirty = TRUE;
   return FALSE;
 }
 
