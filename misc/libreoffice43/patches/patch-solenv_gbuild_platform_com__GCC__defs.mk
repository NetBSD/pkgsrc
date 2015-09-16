$NetBSD: patch-solenv_gbuild_platform_com__GCC__defs.mk,v 1.1 2015/09/16 21:12:39 he Exp $

Pick up and apply some diffs based on

http://pkgs.fedoraproject.org/cgit/libreoffice.git/commit/?id=57cfb98d1c45259f946ff3444eeb6891a030e063

which makes libreoffice43 build with boost 1.59.

--- solenv/gbuild/platform/com_GCC_defs.mk.orig	2015-04-20 19:36:29.000000000 +0000
+++ solenv/gbuild/platform/com_GCC_defs.mk
@@ -47,6 +47,8 @@ gb_CPPU_ENV := gcc3
 gb_AFLAGS := $(AFLAGS)
 
 gb_COMPILERDEFS := \
+	-DBOOST_ERROR_CODE_HEADER_ONLY \
+	-DBOOST_SYSTEM_NO_DEPRECATED \
 	-DCPPU_ENV=$(gb_CPPU_ENV) \
 
 gb_CFLAGS_COMMON := \
