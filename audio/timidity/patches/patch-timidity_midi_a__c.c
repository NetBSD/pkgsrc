$NetBSD: patch-timidity_midi_a__c.c,v 1.2 2017/03/30 18:44:13 nat Exp $

Some MIDI definitions are missing on some platform's soundcard.h, so just use
internal definitions everywhere.

--- timidity/midi_a.c.orig	2009-03-14 15:49:59.000000000 +0000
+++ timidity/midi_a.c
@@ -49,14 +49,7 @@
 #endif
 #include <fcntl.h>
 #include <stdlib.h>
-#ifdef HAVE_SYS_SOUNDCARD_H
-#include <sys/soundcard.h>
-#if defined(__NetBSD__) || defined(__OpenBSD__)
-#include <sys/midiio.h>
-#endif
-#else
 #include "server_defs.h"
-#endif /* HAVE_SYS_SOUNDCARD_H */
 #ifdef WIN32
 #ifndef STDOUT_FILENO
 #define STDOUT_FILENO 1
