$NetBSD: patch-src-demuxers-demux_qt.c,v 1.3 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=527

--- src/demuxers/demux_qt.c.orig	2014-02-26 15:49:10.000000000 +0000
+++ src/demuxers/demux_qt.c
@@ -151,7 +151,7 @@ typedef unsigned int qt_atom;
 #define TRUN_ATOM QT_ATOM('t', 'r', 'u', 'n')
 
 /* placeholder for cutting and pasting
-#define _ATOM QT_ATOM('', '', '', '')
+//#define _ATOM QT_ATOM('', '', '', '')
 */
 
 #define ATOM_PREAMBLE_SIZE 8
