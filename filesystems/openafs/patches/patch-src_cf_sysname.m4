$NetBSD: patch-src_cf_sysname.m4,v 1.2 2026/09/12 15:45:26 jakllsch Exp $

- add support for NetBSD 8, 9, 10, 11; try to support 11.99/12

--- src/cf/sysname.m4.orig	2024-11-12 18:06:26.000000000 +0000
+++ src/cf/sysname.m4
@@ -398,6 +398,11 @@ case $AFS_SYSNAME in
     *_nbsd50)   AFS_PARAM_COMMON=param.nbsd50.h  ;;
     *_nbsd60)   AFS_PARAM_COMMON=param.nbsd60.h  ;;
     *_nbsd70)   AFS_PARAM_COMMON=param.nbsd70.h  ;;
+    *_nbsd80)   AFS_PARAM_COMMON=param.nbsd80.h  ;;
+    *_nbsd90)   AFS_PARAM_COMMON=param.nbsd90.h  ;;
+    *_nbsd100)  AFS_PARAM_COMMON=param.nbsd100.h  ;;
+    *_nbsd110)  AFS_PARAM_COMMON=param.nbsd110.h  ;;
+    *_nbsd120)  AFS_PARAM_COMMON=param.nbsd120.h  ;;
     *_obsd31)   AFS_PARAM_COMMON=param.obsd31.h  ;;
     *_obsd32)   AFS_PARAM_COMMON=param.obsd32.h  ;;
     *_obsd33)   AFS_PARAM_COMMON=param.obsd33.h  ;;
