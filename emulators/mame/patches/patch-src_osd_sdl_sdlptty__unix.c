$NetBSD: patch-src_osd_sdl_sdlptty__unix.c,v 1.1 2015/11/13 14:11:49 wiz Exp $

https://github.com/mamedev/mame/pull/464

--- src/osd/sdl/sdlptty_unix.c.orig	2015-10-28 07:06:12.000000000 +0000
+++ src/osd/sdl/sdlptty_unix.c
@@ -19,6 +19,7 @@
 # include <termios.h>
 # include <libutil.h>
 #elif defined(SDLMAME_NETBSD) || defined(SDLMAME_MACOSX)
+# include <termios.h>
 # include <util.h>
 #elif defined(SDLMAME_OPENBSD)
 # include <termios.h>
