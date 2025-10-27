$NetBSD: patch-core_sdl_sdl__gamepad.h,v 1.1 2025/10/27 22:57:36 nia Exp $

Fix build on NetBSD.

--- core/sdl/sdl_gamepad.h.orig	2025-10-27 10:20:22.824360631 +0000
+++ core/sdl/sdl_gamepad.h
@@ -308,7 +308,7 @@ public:
 		if (rumblePower == 0)
 			return 0;
 		else
-			return (u16)std::min(power * 65535.f / std::pow(1.06f, 100.f - rumblePower), 65535.f);
+			return (u16)std::min(power * 65535.f / powf(1.06f, 100.f - rumblePower), 65535.f);
 	}
 	void doRumble(float power, u32 duration_ms)
 	{
