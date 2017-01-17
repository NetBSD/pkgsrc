$NetBSD: patch-omxplayer.cpp,v 1.2 2017/01/17 07:33:50 skrll Exp $

--- omxplayer.cpp.orig	2016-10-10 15:38:42.000000000 +0000
+++ omxplayer.cpp
@@ -83,8 +83,8 @@ bool              m_osd                 
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
