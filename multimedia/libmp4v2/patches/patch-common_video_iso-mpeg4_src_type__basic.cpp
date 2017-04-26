$NetBSD: patch-common_video_iso-mpeg4_src_type__basic.cpp,v 1.1 2017/04/26 14:38:31 maya Exp $

Make GCC 4.5 happier about the prototype

--- common/video/iso-mpeg4/src/type_basic.cpp.orig	2006-08-07 18:26:58.000000000 +0000
+++ common/video/iso-mpeg4/src/type_basic.cpp
@@ -317,7 +317,7 @@ Void CMotionVector::computeMV ()
 	iHalfY = m_vctTrueHalfPel.y - iMVY * 2;
 }
 
-Void CMotionVector::setToZero (Void)
+Void CMotionVector::setToZero ()
 {
 	memset (this, 0, sizeof (*this));
 }
