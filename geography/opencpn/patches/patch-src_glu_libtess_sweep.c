$NetBSD: patch-src_glu_libtess_sweep.c,v 1.1 2016/03/14 11:01:06 bouyer Exp $
Fix segfault; it seems that RegionAbove(regUp) can return NULL

--- src/glu/libtess/sweep.c.orig	2016-02-03 18:44:17.000000000 +0100
+++ src/glu/libtess/sweep.c	2016-02-11 13:50:32.000000000 +0100
@@ -33,6 +33,7 @@
 */
 
 #include "gluos.h"
+#include <stdio.h>
 #include <assert.h>
 #include <stddef.h>
 #include <setjmp.h>		/* longjmp */
@@ -546,7 +547,9 @@
     if( EdgeSign( eUp->Dst, eLo->Org, eUp->Org ) < 0 ) return FALSE;
 
     /* eLo->Org appears to be above eUp, so splice eLo->Org into eUp */
-    RegionAbove(regUp)->dirty = regUp->dirty = TRUE;
+    if (RegionAbove(regUp))
+	RegionAbove(regUp)->dirty = TRUE;
+    regUp->dirty = TRUE;
     if (__gl_meshSplitEdge( eUp->Sym ) == NULL) longjmp(tess->env,1);
     if ( !__gl_meshSplice( eLo->Oprev, eUp ) ) longjmp(tess->env,1);
   }
@@ -584,7 +587,9 @@
     if( EdgeSign( eUp->Dst, eLo->Dst, eUp->Org ) < 0 ) return FALSE;
 
     /* eLo->Dst is above eUp, so splice eLo->Dst into eUp */
-    RegionAbove(regUp)->dirty = regUp->dirty = TRUE;
+    if (RegionAbove(regUp) != NULL)
+        RegionAbove(regUp)->dirty = TRUE;
+    regUp->dirty = TRUE;
     e = __gl_meshSplitEdge( eUp );
     if (e == NULL) longjmp(tess->env,1);
     if ( !__gl_meshSplice( eLo->Sym, e ) ) longjmp(tess->env,1);
@@ -1025,15 +1030,23 @@
   tmp.eUp = vEvent->anEdge->Sym;
   /* __GL_DICTLISTKEY */ /* __gl_dictListSearch */
   regUp = (ActiveRegion *)dictKey( dictSearch( tess->dict, &tmp ));
-  regLo = RegionBelow( regUp );
+  if (regUp == NULL) {
+	fprintf(stderr, "ConnectLeftVertex botch 1\n");
+	return;
+  }
   eUp = regUp->eUp;
-  eLo = regLo->eUp;
 
   /* Try merging with U or L first */
   if( EdgeSign( eUp->Dst, vEvent, eUp->Org ) == 0 ) {
     ConnectLeftDegenerate( tess, regUp, vEvent );
     return;
   }
+  regLo = RegionBelow( regUp );
+  if (regLo == NULL) {
+	fprintf(stderr, "ConnectLeftVertex botch 2\n");
+	return;
+  }
+  eLo = regLo->eUp;
 
   /* Connect vEvent to rightmost processed vertex of either chain.
    * e->Dst is the vertex that we will connect to vEvent.
