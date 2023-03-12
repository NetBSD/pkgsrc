$NetBSD: patch-src_CDtoc.cpp,v 1.1.1.1 2023/03/12 17:29:03 abs Exp $

Add fallback LEADOUT_TRACK_NUMBER = 0xAA for non Win/Mac/Linux

(Linux and Windows also use 0xAA)

--- src/CDtoc.cpp.orig	2022-12-30 01:21:26.000000000 +0000
+++ src/CDtoc.cpp
@@ -76,6 +76,8 @@ uint8_t LEADOUT_TRACK_NUMBER = CDROM_LEA
 #elif defined(_WIN32)
 uint8_t LEADOUT_TRACK_NUMBER =
     0xAA; // NOTE: for WinXP IOCTL_CDROM_READ_TOC_EX code, its 0xA2
+#else
+uint8_t LEADOUT_TRACK_NUMBER = 0xAA;
 #endif
 
 /*
