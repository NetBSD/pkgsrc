$NetBSD: patch-src_cf_osconf.m4,v 1.2 2022/03/19 16:19:02 jakllsch Exp $

- support NetBSD newer than 7

--- src/cf/osconf.m4.orig	2021-12-09 17:07:41.000000000 +0000
+++ src/cf/osconf.m4
@@ -189,7 +189,7 @@ case $AFS_SYSNAME in
 		XCFLAGS="-O2 -pipe -fPIC"
 		;;
 
-	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*|*nbsd7*)
+	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*|*nbsd7*|*nbsd*0)
 		MT_CFLAGS='-pthread -D_REENTRANT'
 		PAM_OPTMZ=-O2
 		PAM_CFLAGS="-pipe -fPIC"
