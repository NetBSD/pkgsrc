$NetBSD: patch-acinclude.m4,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- acinclude.m4.orig	2012-04-22 23:40:23.000000000 -0400
+++ acinclude.m4	2012-04-28 19:04:26.000000000 -0400
@@ -723,6 +723,7 @@
     *_nbsd40)   AFS_PARAM_COMMON=param.nbsd40.h  ;;
     *_nbsd50)   AFS_PARAM_COMMON=param.nbsd50.h  ;;
     *_nbsd60)   AFS_PARAM_COMMON=param.nbsd60.h  ;;
+    *_nbsd70)   AFS_PARAM_COMMON=param.nbsd70.h  ;;
     *_obsd31)   AFS_PARAM_COMMON=param.obsd31.h  ;;
     *_obsd32)   AFS_PARAM_COMMON=param.obsd32.h  ;;
     *_obsd33)   AFS_PARAM_COMMON=param.obsd33.h  ;;
