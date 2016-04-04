$NetBSD: patch-acinclude.m4,v 1.1 2016/04/04 12:48:29 jakllsch Exp $

--- acinclude.m4.orig	2016-03-16 14:31:22.000000000 +0000
+++ acinclude.m4
@@ -777,6 +777,9 @@ case $AFS_SYSNAME in
     *_nbsd40)   AFS_PARAM_COMMON=param.nbsd40.h  ;;
     *_nbsd50)   AFS_PARAM_COMMON=param.nbsd50.h  ;;
     *_nbsd60)   AFS_PARAM_COMMON=param.nbsd60.h  ;;
+    *_nbsd70)   AFS_PARAM_COMMON=param.nbsd70.h  ;;
+    *_nbsd80)   AFS_PARAM_COMMON=param.nbsd80.h  ;;
+    *_nbsd90)   AFS_PARAM_COMMON=param.nbsd90.h  ;;
     *_obsd31)   AFS_PARAM_COMMON=param.obsd31.h  ;;
     *_obsd32)   AFS_PARAM_COMMON=param.obsd32.h  ;;
     *_obsd33)   AFS_PARAM_COMMON=param.obsd33.h  ;;
