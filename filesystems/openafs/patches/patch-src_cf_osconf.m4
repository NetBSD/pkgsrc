$NetBSD: patch-src_cf_osconf.m4,v 1.1 2016/04/04 12:48:29 jakllsch Exp $

--- src/cf/osconf.m4.orig	2016-03-16 14:31:22.000000000 +0000
+++ src/cf/osconf.m4
@@ -205,7 +205,7 @@ case $AFS_SYSNAME in
 		XCFLAGS="-O2 -pipe -fPIC"
 		;;
 
-	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*)
+	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*|*nbsd*0)
 		MT_CFLAGS='-DAFS_PTHREAD_ENV -pthread -D_REENTRANT ${XCFLAGS}'
 		MT_LIBS="-pthread"
 		PAM_OPTMZ=-O2
