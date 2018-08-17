$NetBSD: patch-src_burner_libretro_libretro.cpp,v 1.1 2018/08/17 12:54:48 nia Exp $

Fix for "Dip switches not working? #185"

Upstream commit: bbae856806f589286f340e55c9653b0f6d45120f

--- src/burner/libretro/libretro.cpp.orig	2018-04-08 06:33:58.000000000 +0000
+++ src/burner/libretro/libretro.cpp
@@ -165,6 +165,7 @@ INT32 nFireButtons = 0;
 bool bStreetFighterLayout = false;
 bool bButtonMapped = false;
 bool bVolumeIsFireButton = false;
+INT32 bDip = 1;
 
 // libretro globals
 void retro_set_video_refresh(retro_video_refresh_t cb) { video_cb = cb; }
@@ -3391,9 +3392,14 @@ INT32 GameInpInit()
 	}
 	memset(GameInp, 0, nSize);
 
-	GameInpBlank(1);
+	// Initializing dipswitches several times is causing issues (#185)
+	// So let's use a variable (bDip global) to avoid initializing them several times
+	GameInpBlank(bDip);
 
-	InpDIPSWResetDIPs();
+	if(bDip)
+		InpDIPSWResetDIPs();
+
+	bDip = 0;
 
 	GameInpInitMacros();
 
