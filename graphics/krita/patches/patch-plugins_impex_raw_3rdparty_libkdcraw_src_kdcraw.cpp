--- plugins/impex/raw/3rdparty/libkdcraw/src/kdcraw.cpp.orig	2023-04-12 18:35:32.974065836 -0500
+++ plugins/impex/raw/3rdparty/libkdcraw/src/kdcraw.cpp	2023-04-12 18:33:25.495325885 -0500
@@ -383,7 +383,7 @@
     d->setProgress(0.3);
 
     raw.imgdata.params.output_bps  = 16;
-    raw.imgdata.params.shot_select = shotSelect;
+    raw.imgdata.rawparams.shot_select = shotSelect;
     ret                            = raw.unpack();
 
     if (ret != LIBRAW_SUCCESS)
