$NetBSD: patch-src_osd_sdl_sdl.mak,v 1.1 2013/11/14 08:18:21 wiz Exp $

r26155 | rbelmont | 2013-11-14 04:58:10 +0100 (Thu, 14 Nov 2013) | 3 lines

SDL: fix non-Qt non-Windows build (MT #5364) [R. Belmont]

--- src/osd/sdl/sdl.mak.orig	2013-11-05 07:59:52.000000000 +0000
+++ src/osd/sdl/sdl.mak
@@ -59,17 +59,16 @@ USE_DISPATCH_GL = 1
 # active development on sdlmame or SDL.
 
 # uncomment the next line to compile and link against SDL2.0
-
 # SDL_LIBVER = sdl2
 
-# uncomment the next line to use couriersud's multi-keyboard patch for sdl2.0
+# uncomment the next line to use couriersud's multi-keyboard patch for SDL 2.1? (this API was removed prior to the 2.0 release)
 # SDL2_MULTIAPI = 1
 
 # uncomment the next line to specify where you have installed
 # SDL. Equivalent to the ./configure --prefix=<path>
 # SDL_INSTALL_ROOT = /usr/local/sdl13
 
-# uncomment to disable the Qt debugger and fall back to a system default
+# uncomment to disable the Qt debugger (on non-OSX this disables all debugging)
 # NO_USE_QTDEBUG = 1
 
 # uncomment to disable MIDI
@@ -307,11 +306,6 @@ SDLMAIN = $(SDLOBJ)/main.o
 LDFLAGS += -Wl,--allow-multiple-definition
 SDL_NETWORK = pcap
 
-# if no Qt, no debugger
-ifdef NO_USE_QTDEBUG
-NO_DEBUGGER = 1
-endif
-
 # enable UNICODE
 DEFS += -Dmain=utf8_main -DUNICODE -D_UNICODE
 LDFLAGS += -municode
@@ -355,6 +349,13 @@ ifeq ($(BASE_TARGETOS),)
 $(error $(TARGETOS) not supported !)
 endif
 
+# if no Qt and not OS X, no debugger
+ifneq ($(TARGETOS),macosx)
+ifdef NO_USE_QTDEBUG
+NO_DEBUGGER = 1
+endif
+endif
+
 #-------------------------------------------------
 # object and source roots
 #-------------------------------------------------
@@ -528,8 +529,6 @@ endif
 QT_INSTALL_HEADERS = $(shell $(QMAKE) -query QT_INSTALL_HEADERS)
 INCPATH += -I$(QT_INSTALL_HEADERS)/QtCore -I$(QT_INSTALL_HEADERS)/QtGui -I$(QT_INSTALL_HEADERS)
 LIBS += -L$(shell $(QMAKE) -query QT_INSTALL_LIBS) -lQtGui -lQtCore
-else
-DEBUGOBJS = $(SDLOBJ)/debugwin.o $(SDLOBJ)/dview.o $(SDLOBJ)/debug-sup.o $(SDLOBJ)/debug-intf.o
 endif
 
 LIBGL = -lGL
