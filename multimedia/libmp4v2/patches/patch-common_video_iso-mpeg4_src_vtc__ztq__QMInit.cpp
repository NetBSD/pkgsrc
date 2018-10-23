$NetBSD: patch-common_video_iso-mpeg4_src_vtc__ztq__QMInit.cpp,v 1.1 2018/10/23 10:45:01 jperkin Exp $

Avoid ERR redefinition.

--- common/video/iso-mpeg4/src/vtc_ztq_QMInit.cpp.orig	2005-05-09 21:29:49.000000000 +0000
+++ common/video/iso-mpeg4/src/vtc_ztq_QMInit.cpp
@@ -64,6 +64,9 @@
 #include "QMUtils.hpp"
 #include "QM.hpp"
 
+#ifdef __sun
+#undef ERR
+#endif
 
 Int CVTCCommon::ztqQListInit()
 {
