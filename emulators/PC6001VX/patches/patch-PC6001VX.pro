$NetBSD: patch-PC6001VX.pro,v 1.1 2017/01/15 11:11:01 tsutsui Exp $

- pull following updates (use pkg-config more properly) from the upstream:
 https://github.com/eighttails/PC6001VX/commit/19367cdbaf4b624a64a962168767ae9fb1aef8c4
 https://github.com/eighttails/PC6001VX/commit/d4a7179f34a6eb454bce898815ab4f5ab767577b
 https://github.com/eighttails/PC6001VX/commit/fd695b875266be21fe6be22a918be6ea7cdc7f53
 https://github.com/eighttails/PC6001VX/commit/179408dc05377ea3c19f504f382436874466efa5

--- PC6001VX.pro.orig	2016-08-27 12:19:26.000000000 +0000
+++ PC6001VX.pro
@@ -4,7 +4,7 @@
 #
 #-------------------------------------------------
 
-QT       += core gui widgets network
+QT += core gui widgets network
 
 TARGET = PC6001VX
 TEMPLATE = app
@@ -16,24 +16,30 @@
 #Define for Qt dependent code
 DEFINES += QTP6VX
 
-#Disable joystick support.If joystick support is disabled, PC6001VX does not depend on SDL2.
+#Disable joystick support.If uncommented below, PC6001VX does not depend on SDL2.
 #DEFINES += NOJOYSTICK
 
+#Disable joystick support.If uncommented below, PC6001VX does not depend on ffmpeg.
+#DEFINES += NOAVI
+
+#Disable debug features.For low performance machine.
+#DEFINES += NOMONITOR
+
 #Other feature control flags.
 #DEFINES += NOSINGLEAPP
 #DEFINES += NOOPENGL
 #DEFINES += NOSOUND
-#DEFINES += NOAVI
 #DEFINES += REPLAYDEBUG
 #DEFINES += AUTOSUSPEND
 
 debug:DEFINES += DEBUG
 INCLUDEPATH += src/Qt src/Qt/qtsingleapplication
 
-linux{
+#Configuration for UNIX variants
+unix {
 #Configuration for Android
-android{
-DEFINES += NOSINGLEAPP NOJOYSTICK NOMONITOR NOAVI ALWAYSFULLSCREEN AUTOSUSPEND USE_QGLWIDGET
+android {
+DEFINES += NOSINGLEAPP NOJOYSTICK NOMONITOR NOAVI ALWAYSFULLSCREEN AUTOSUSPEND
 #Set "ROM Path in target device" to "CUSTOM_ROM_PATH environment variable on build host"
 debug:DEFINES += CUSTOMROMPATH=\\\"$$(CUSTOM_ROM_PATH)\\\"
 }
@@ -56,24 +62,24 @@
 #Configuration for X11(XCB)
 DEFINES += USE_X11
 QT += x11extras
-LIBS += -lX11
+QMAKE_CXXFLAGS += $$system(pkg-config --cflags x11)
+LIBS += $$system(pkg-config --libs x11)
 }
 }
 
 #Configuration for Windows
-win32:{
+win32 {
 DEFINES += WIN32
 #On Windows, links libraries statically as long as possible.
 QMAKE_LFLAGS += -static -lpthread
 RC_ICONS += src/win32/PC6001VX.ico
+}
 
 !contains(DEFINES, NOJOYSTICK) {
-#On Windows, referes SDL_DIR environment variable to search SDL2
-QMAKE_CXXFLAGS += -I$$(SDL_DIR)/include -Dmain=SDL_main
-LIBS += -L$$(SDL_DIR)/lib -lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid
+win32 {
+LIBS += -lmingw32 -lSDL2main -lSDL2 -lversion -mwindows
 }
-} else {
-!contains(DEFINES, NOJOYSTICK) {
+unix {
 QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
 LIBS += $$system(sdl2-config --libs)
 }
@@ -82,16 +88,23 @@
 !contains(DEFINES, NOOPENGL) {
 QT += opengl
 }
+
 !contains(DEFINES, NOSOUND) {
 QT += multimedia
 SOURCES += \
     src/Qt/wavfile.cpp \
     src/Qt/utils.cpp
 }
+
 !contains(DEFINES, NOAVI) {
 DEFINES += __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS
-LIBS += -lavformat -lavcodec -lswscale -lavutil -lswresample
-win32:LIBS += -lvorbisenc -lvorbis -logg -lvpx
+win32 {
+LIBS += -lavformat -lavcodec -lswscale -lavutil -lswresample -lvorbisenc -lvorbis -logg -lvpx
+}
+unix {
+QMAKE_CXXFLAGS += $$system(pkg-config --cflags libavformat libavcodec libswscale libavutil libswresample)
+LIBS += $$system(pkg-config --libs libavformat libavcodec libswscale libavutil libswresample)
+}
 }
 
 SOURCES += \
