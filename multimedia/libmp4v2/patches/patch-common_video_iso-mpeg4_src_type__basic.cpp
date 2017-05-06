$NetBSD: patch-common_video_iso-mpeg4_src_type__basic.cpp,v 1.2 2017/05/06 18:12:00 maya Exp $

Make GCC 4.5.3 happier - it type errors on this declaration

--- common/video/iso-mpeg4/src/type_basic.cpp.orig	2017-05-06 17:53:07.101492438 +0000
+++ common/video/iso-mpeg4/src/type_basic.cpp
@@ -317,7 +317,7 @@ Void CMotionVector::computeMV ()
 	iHalfY = m_vctTrueHalfPel.y - iMVY * 2;
 }
 
-Void CMotionVector::setToZero (Void)
+Void CMotionVector::setToZero ()
 {
 	memset (this, 0, sizeof (*this));
 }
