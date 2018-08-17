$NetBSD: patch-src_burn_drv_galaxian_d__galaxian.cpp,v 1.1 2018/08/17 12:54:48 nia Exp $

Fixing The End sound volume (#199)

Upstream commit: b5550733fb162ae4c5de15d2f9c42db4a919c3df

--- src/burn/drv/galaxian/d_galaxian.cpp.orig	2018-04-08 06:33:58.000000000 +0000
+++ src/burn/drv/galaxian/d_galaxian.cpp
@@ -16864,12 +16864,12 @@ static INT32 TheendInit()
 	
 	KonamiPPIInit();
 	
-	filter_rc_set_src_gain(0, 0.02);
-	filter_rc_set_src_gain(1, 0.02);
-	filter_rc_set_src_gain(2, 0.02);
-	filter_rc_set_src_gain(3, 0.02);
-	filter_rc_set_src_gain(4, 0.02);
-	filter_rc_set_src_gain(5, 0.02);
+	filter_rc_set_src_gain(0, 0.12);
+	filter_rc_set_src_gain(1, 0.12);
+	filter_rc_set_src_gain(2, 0.12);
+	filter_rc_set_src_gain(3, 0.12);
+	filter_rc_set_src_gain(4, 0.12);
+	filter_rc_set_src_gain(5, 0.12);
 	
 	return nRet;
 }
