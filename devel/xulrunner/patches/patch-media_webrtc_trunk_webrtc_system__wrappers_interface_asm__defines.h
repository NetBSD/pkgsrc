$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_interface_asm__defines.h,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/interface/asm_defines.h.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/interface/asm_defines.h
@@ -11,7 +11,7 @@
 #ifndef WEBRTC_SYSTEM_WRAPPERS_INTERFACE_ASM_DEFINES_H_
 #define WEBRTC_SYSTEM_WRAPPERS_INTERFACE_ASM_DEFINES_H_
 
-#if defined(__linux__) && defined(__ELF__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__ELF__)
 .section .note.GNU-stack,"",%progbits
 #endif
 
