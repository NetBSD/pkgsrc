$NetBSD: patch-src-demuxers-demux_qt.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/demuxers/demux_qt.c.orig	2011-08-30 10:17:53.000000000 +0000
+++ src/demuxers/demux_qt.c
@@ -126,7 +126,7 @@ typedef unsigned int qt_atom;
 #define QTIM_ATOM QT_ATOM('q', 't', 'i', 'm')
 
 /* placeholder for cutting and pasting */
-#define _ATOM QT_ATOM('', '', '', '')
+//#define _ATOM QT_ATOM('', '', '', '')
 
 #define ATOM_PREAMBLE_SIZE 8
 #define PALETTE_COUNT 256
