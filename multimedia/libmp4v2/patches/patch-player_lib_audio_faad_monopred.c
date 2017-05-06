$NetBSD: patch-player_lib_audio_faad_monopred.c,v 1.1 2017/05/06 18:12:00 maya Exp $

We're ignoring the return value anyway, so don't assign
it to anything.

--- player/lib/audio/faad/monopred.c.orig	2002-01-11 00:55:17.000000000 +0000
+++ player/lib/audio/faad/monopred.c
@@ -90,10 +90,9 @@ static void flt_round(float *pf)
 static void inv_table_flt_round(float *ftmp)
 {
     int exp;
-    double mnt;
     float descale;
 
-    mnt = frexp((double)*ftmp, &exp);
+    (void)frexp((double)*ftmp, &exp);
     descale = (float)ldexp(1.0, exp + 15);
     *ftmp += descale;
     *ftmp -= descale;
