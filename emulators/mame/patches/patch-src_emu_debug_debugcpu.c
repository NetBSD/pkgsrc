$NetBSD: patch-src_emu_debug_debugcpu.c,v 1.2 2011/02/11 12:49:33 abs Exp $

--- src/emu/debug/debugcpu.c.orig	2010-12-31 16:41:26.000000000 +0000
+++ src/emu/debug/debugcpu.c
@@ -51,7 +51,7 @@
 #include "xmlfile.h"
 #include <ctype.h>
 #include <zlib.h>
-#ifdef SDLMAME_FREEBSD
+#if defined(SDLMAME_FREEBSD) || defined(SDLMAME_NETBSD)
 # undef tolower
 #endif
 
