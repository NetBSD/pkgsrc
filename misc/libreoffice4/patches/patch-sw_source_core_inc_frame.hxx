$NetBSD: patch-sw_source_core_inc_frame.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- sw/source/core/inc/frame.hxx.orig	2014-01-18 18:17:42.000000000 +0000
+++ sw/source/core/inc/frame.hxx
@@ -226,6 +226,8 @@ enum MakePageType
  * level: pages, headers, footers, etc. (Inside a paragraph SwLinePortion
  * instances are used.)
  */
+SwFrm *SaveCntnt( SwLayoutFrm *, SwFrm* pStart = NULL );
+
 class SwFrm: public SwClient, public SfxBroadcaster
 {
     // the hidden Frm
@@ -234,7 +236,7 @@ class SwFrm: public SwClient, public Sfx
     friend class SwLooping;
 
     // voids lower during creation of a column
-    friend SwFrm *SaveCntnt( SwLayoutFrm *, SwFrm* pStart = NULL );
+    friend SwFrm *SaveCntnt( SwLayoutFrm *, SwFrm* pStart );
     friend void   RestoreCntnt( SwFrm *, SwLayoutFrm *, SwFrm *pSibling, bool bGrow );
 
 #ifdef DBG_UTIL
