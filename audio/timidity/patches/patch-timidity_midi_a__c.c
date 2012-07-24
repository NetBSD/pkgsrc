$NetBSD: patch-timidity_midi_a__c.c,v 1.1 2012/07/24 19:47:44 jperkin Exp $

Some MIDI definitions are missing on some platform's soundcard.h, so just use
internal definitions everywhere.

--- timidity/midi_a.c.orig	2012-07-24 00:44:02.879194950 +0300
+++ timidity/midi_a.c	2012-07-24 00:44:21.200309747 +0300
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
