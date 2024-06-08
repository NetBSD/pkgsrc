$NetBSD: patch-src_osd_modules_input_input__sdl.cpp,v 1.3 2024/06/08 14:47:48 wiz Exp $

Fix "lround is not a member of std::" on NetBSD.
https://github.com/mamedev/mame/issues/12458

--- src/osd/modules/input/input_sdl.cpp.orig	2024-05-29 17:42:54.000000000 +0000
+++ src/osd/modules/input/input_sdl.cpp
@@ -786,8 +786,8 @@ public:
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
@@ -888,8 +888,8 @@ public:
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
