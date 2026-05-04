$NetBSD: patch-jfaudiolib_src_midi.c,v 1.1 2026/05/04 12:28:52 nia Exp $

Only include <alloca.h> on systems that have it.

--- jfaudiolib/src/midi.c.orig	2025-12-26 07:57:03.000000000 +0000
+++ jfaudiolib/src/midi.c
@@ -34,7 +34,7 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #include <stdio.h>
 #ifdef _WIN32
 # include <malloc.h>
-#else
+#elif defined(__linux__) || defined(__sun)
 # include <alloca.h>
 #endif
 #include "sndcards.h"
