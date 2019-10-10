$NetBSD: patch-setup_WRBGCFLS.i,v 1.1 2019/10/10 13:54:17 ryoon Exp $

* Detect libX11 properly

--- setup/WRBGCFLS.i.orig	2018-08-19 11:02:48.000000000 +0000
+++ setup/WRBGCFLS.i
@@ -363,8 +363,8 @@ LOCALPROC WriteBashGccMakeFile(void)
 				WriteCStrToDestFile(" -lXext");
 #endif
 				if (gbk_targfam_nbsd == gbo_targfam) {
-					WriteCStrToDestFile(" -L/usr/X11R7/lib");
-					WriteCStrToDestFile(" -R/usr/X11R7/lib");
+					WriteCStrToDestFile(" -L@X11BASE@/lib");
+					WriteCStrToDestFile(" @COMPILER_RPATH_FLAG@@X11BASE@/lib");
 				} else if (gbk_targfam_dbsd == gbo_targfam) {
 					WriteCStrToDestFile(" -L/usr/pkg/lib");
 				} else if (gbk_targfam_minx == gbo_targfam) {
