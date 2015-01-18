$NetBSD: patch-help.h,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

--- help.h.orig	2015-01-18 22:39:31.000000000 +0000
+++ help.h
@@ -28,8 +28,8 @@
 "        --no-osd                Do not display status information on screen\n"
 "        --no-keys               Disable keyboard input (prevents hangs for certain TTYs)\n"
 "        --subtitles path        External subtitles in UTF-8 srt format\n"
-"        --font path             Default: /usr/share/fonts/truetype/freefont/FreeSans.ttf\n"
-"        --italic-font path      Default: /usr/share/fonts/truetype/freefont/FreeSansOblique.ttf\n"
+"        --font path             Default: " PREFIX "/share/fonts/X11/TTF/FreeSans.ttf\n"
+"        --italic-font path      Default: " PREFIX "/share/fonts/X11/TTF/FreeSansOblique.ttf\n"
 "        --font-size size        Font size in 1/1000 screen height (default: 55)\n"
 "        --align left/center     Subtitle alignment (default: left)\n"
 "        --no-ghost-box          No semitransparent boxes behind subtitles\n"
