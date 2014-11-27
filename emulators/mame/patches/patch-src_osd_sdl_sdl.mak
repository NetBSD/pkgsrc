$NetBSD: patch-src_osd_sdl_sdl.mak,v 1.3 2014/11/27 12:46:59 wiz Exp $

Choose a network interface type for NetBSD to fix linking.

--- src/osd/sdl/sdl.mak.orig	2014-11-26 10:37:58.000000000 +0000
+++ src/osd/sdl/sdl.mak
@@ -235,6 +235,7 @@ BASE_TARGETOS = unix
 SYNC_IMPLEMENTATION = ntc
 LIBS += -lutil
 NO_USE_MIDI = 1
+SDL_NETWORK = pcap
 endif
 
 ifeq ($(TARGETOS),solaris)
