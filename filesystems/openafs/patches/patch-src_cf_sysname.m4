$NetBSD: patch-src_cf_sysname.m4,v 1.1 2022/03/19 16:19:02 jakllsch Exp $

- add support for NetBSD 8 and 9; try to support -current/10 and 10.99/11

--- src/cf/sysname.m4.orig	2021-12-09 17:07:41.000000000 +0000
+++ src/cf/sysname.m4
@@ -342,6 +342,10 @@ case $AFS_SYSNAME in
     *_nbsd50)   AFS_PARAM_COMMON=param.nbsd50.h  ;;
     *_nbsd60)   AFS_PARAM_COMMON=param.nbsd60.h  ;;
     *_nbsd70)   AFS_PARAM_COMMON=param.nbsd70.h  ;;
+    *_nbsd80)   AFS_PARAM_COMMON=param.nbsd80.h  ;;
+    *_nbsd90)   AFS_PARAM_COMMON=param.nbsd90.h  ;;
+    *_nbsd100)  AFS_PARAM_COMMON=param.nbsd90.h  ;;
+    *_nbsd110)  AFS_PARAM_COMMON=param.nbsd90.h  ;;
     *_obsd31)   AFS_PARAM_COMMON=param.obsd31.h  ;;
     *_obsd32)   AFS_PARAM_COMMON=param.obsd32.h  ;;
     *_obsd33)   AFS_PARAM_COMMON=param.obsd33.h  ;;
