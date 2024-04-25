$NetBSD: patch-src_osd_modules_input_input__sdl.cpp,v 1.1 2024/04/25 09:51:16 wiz Exp $

Fix "lround is not a member of std::" on NetBSD.

--- src/osd/modules/input/input_sdl.cpp.orig	2024-04-25 09:49:02.743315265 +0000
+++ src/osd/modules/input/input_sdl.cpp
@@ -738,8 +738,8 @@ public:
 		case SDL_MOUSEWHEEL:
 			// adjust SDL 1-per-click to match Win32 120-per-click
 #if SDL_VERSION_ATLEAST(2, 0, 18)
-			m_v += std::lround(event.wheel.preciseY * 120 * input_device::RELATIVE_PER_PIXEL);
-			m_h += std::lround(event.wheel.preciseX * 120 * input_device::RELATIVE_PER_PIXEL);
+			m_v += lround(event.wheel.preciseY * 120 * input_device::RELATIVE_PER_PIXEL);
+			m_h += lround(event.wheel.preciseX * 120 * input_device::RELATIVE_PER_PIXEL);
 #else
 			m_v += event.wheel.y * 120 * input_device::RELATIVE_PER_PIXEL;
 			m_h += event.wheel.x * 120 * input_device::RELATIVE_PER_PIXEL;
