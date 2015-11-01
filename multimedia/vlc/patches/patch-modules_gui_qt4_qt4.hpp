$NetBSD: patch-modules_gui_qt4_qt4.hpp,v 1.1 2015/11/01 20:15:06 tnn Exp $

We need to include vlc_atomic.h early. Something pulls it in later with
C linkage and that makes clang sad (#include <atomic> needs C++ linkage).

--- modules/gui/qt4/qt4.hpp.orig	2014-11-16 18:57:59.000000000 +0000
+++ modules/gui/qt4/qt4.hpp
@@ -29,6 +29,7 @@
 # include "config.h"
 #endif
 
+#include <vlc_atomic.h>
 #include <vlc_common.h>    /* VLC_COMMON_MEMBERS for vlc_interface.h */
 #include <vlc_interface.h> /* intf_thread_t */
 #include <vlc_playlist.h>  /* playlist_t */
