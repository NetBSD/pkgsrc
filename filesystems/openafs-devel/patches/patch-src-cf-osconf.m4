$NetBSD: patch-src-cf-osconf.m4,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/cf/osconf.m4.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/cf/osconf.m4	2012-04-28 19:01:31.000000000 -0400
@@ -191,7 +191,7 @@
 		XCFLAGS="-O2 -pipe -fPIC"
 		;;
 
-	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*)
+	*nbsd2*|*nbsd3*|*nbsd4*|*nbsd5*|*nbsd6*|*nbsd7*)
 		MT_CFLAGS='-pthread -D_REENTRANT'
 		PAM_OPTMZ=-O2
 		PAM_CFLAGS="-pipe -fPIC"
