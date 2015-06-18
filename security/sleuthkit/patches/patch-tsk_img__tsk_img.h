$NetBSD: patch-tsk_img__tsk_img.h,v 1.1 2015/06/18 13:01:44 pettai Exp $

Fix for pytsk, originally from FreeBSD ports

--- tsk/img/tsk_img.h.orig	2014-01-27 03:27:03.000000000 +0000
+++ tsk/img/tsk_img.h
@@ -66,6 +66,8 @@ extern "C" {
 
         TSK_IMG_TYPE_EWF_EWF = 0x0040,  ///< EWF version
 
+        TSK_IMG_TYPE_EXTERNAL = 0x1000,  ///< external defined format which at least implements TSK_IMG_INFO, used by pytsk
+
         TSK_IMG_TYPE_UNSUPP = 0xffff,   ///< Unsupported disk image type
     } TSK_IMG_TYPE_ENUM;
 
