$NetBSD: patch-src_config_param.nbsd60.h,v 1.1 2012/12/01 15:22:32 jakllsch Exp $

--- src/config/param.nbsd60.h.orig	2012-03-26 23:03:34.000000000 +0000
+++ src/config/param.nbsd60.h
@@ -3,6 +3,7 @@
 #ifndef	AFS_PARAM_COMMON_H
 #define	AFS_PARAM_COMMON_H 1
 
+#define AFS_64BIT_ENV  1
 #define AFS_NAMEI_ENV  1	/* User space interface to file system */
 #define AFS_64BIT_IOPS_ENV 1	/* Needed for NAMEI */
 #define AFS_64BIT_CLIENT 1
