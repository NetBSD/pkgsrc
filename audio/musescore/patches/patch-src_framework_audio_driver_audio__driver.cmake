$NetBSD: patch-src_framework_audio_driver_audio__driver.cmake,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/framework/audio/driver/audio_driver.cmake.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/framework/audio/driver/audio_driver.cmake
@@ -34,7 +34,7 @@ if (OS_IS_WIN)
         ${CMAKE_CURRENT_LIST_DIR}/platform/win/audiodeviceslistener.cpp
         ${CMAKE_CURRENT_LIST_DIR}/platform/win/audiodeviceslistener.h
     )
-elseif(OS_IS_LIN OR OS_IS_FBSD)
+elseif(OS_IS_LIN OR OS_IS_FBSD OR OS_IS_NBSD)
     set(AUDIO_DRIVER_SRC
         ${CMAKE_CURRENT_LIST_DIR}/platform/lin/alsaaudiodriver.cpp
         ${CMAKE_CURRENT_LIST_DIR}/platform/lin/alsaaudiodriver.h
