$NetBSD: patch-src-demuxers-demux_qt.c,v 1.2 2014/04/17 13:53:47 wiz Exp $

--- src/demuxers/demux_qt.c.orig	2014-02-26 15:49:10.000000000 +0000
+++ src/demuxers/demux_qt.c
@@ -151,7 +151,7 @@ typedef unsigned int qt_atom;
 #define TRUN_ATOM QT_ATOM('t', 'r', 'u', 'n')
 
 /* placeholder for cutting and pasting
-#define _ATOM QT_ATOM('', '', '', '')
+//#define _ATOM QT_ATOM('', '', '', '')
 */
 
 #define ATOM_PREAMBLE_SIZE 8
