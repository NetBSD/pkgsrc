$NetBSD: patch-src_kdcraw.cpp,v 1.1 2023/03/18 05:55:11 wiz Exp $

Fix build with libraw-0.21.

--- src/kdcraw.cpp.orig	2022-07-13 12:24:57.000000000 +0000
+++ src/kdcraw.cpp
@@ -357,7 +357,11 @@ bool KDcraw::extractRAWData(const QStrin
     d->setProgress(0.3);
 
     raw.imgdata.params.output_bps  = 16;
+#if LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 21)
+    raw.imgdata.rawparams.shot_select = shotSelect;
+#else
     raw.imgdata.params.shot_select = shotSelect;
+#endif
     ret                            = raw.unpack();
 
     if (ret != LIBRAW_SUCCESS)
