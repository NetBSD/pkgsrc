$NetBSD: patch-solenv_gbuild_platform_com__MSC__defs.mk,v 1.1 2015/09/23 20:45:50 joerg Exp $

Pick up and apply some diffs based on

http://pkgs.fedoraproject.org/cgit/libreoffice.git/commit/?id=57cfb98d1c45259f946ff3444eeb6891a030e063

which makes libreoffice43 build with boost 1.59.

--- solenv/gbuild/platform/com_MSC_defs.mk.orig	2015-04-20 19:36:29.000000000 +0000
+++ solenv/gbuild/platform/com_MSC_defs.mk
@@ -41,6 +41,9 @@ gb_CXX := $(CXX)
 endif
 
 gb_COMPILERDEFS := \
+	-DBOOST_ERROR_CODE_HEADER_ONLY \
+	-DBOOST_OPTIONAL_USE_OLD_DEFINITION_OF_NONE \
+	-DBOOST_SYSTEM_NO_DEPRECATED \
 	-D_CRT_NON_CONFORMING_SWPRINTFS \
 	-D_CRT_NONSTDC_NO_DEPRECATE \
 	-D_CRT_SECURE_NO_DEPRECATE \
