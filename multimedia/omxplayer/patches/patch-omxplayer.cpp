$NetBSD: patch-omxplayer.cpp,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

--- omxplayer.cpp.orig	2015-01-12 15:10:50.000000000 +0000
+++ omxplayer.cpp
@@ -23,7 +23,9 @@
 #include <stdint.h>
 #include <termios.h>
 #include <sys/mman.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 #include <sys/ioctl.h>
 #include <getopt.h>
 #include <string.h>
@@ -90,8 +92,8 @@ bool              m_osd                 
 bool              m_no_keys             = false;
 std::string       m_external_subtitles_path;
 bool              m_has_external_subtitles = false;
-std::string       m_font_path           = "/usr/share/fonts/truetype/freefont/FreeSans.ttf";
-std::string       m_italic_font_path    = "/usr/share/fonts/truetype/freefont/FreeSansOblique.ttf";
+std::string       m_font_path           = PREFIX "/share/fonts/X11/TTF/FreeSans.ttf";
+std::string       m_italic_font_path    = PREFIX "/share/fonts/X11/TTF/FreeSansOblique.ttf";
 std::string       m_dbus_name           = "org.mpris.MediaPlayer2.omxplayer";
 bool              m_asked_for_font      = false;
 bool              m_asked_for_italic_font = false;
