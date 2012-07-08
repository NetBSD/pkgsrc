$NetBSD: patch-interface_server__c.c,v 1.1 2012/07/08 09:51:31 wiz Exp $

Some MIDI definitions are missing on e.g. NetBSD, so just use
internal definitions everywhere.

--- interface/server_c.c.orig	2012-06-01 03:33:06.000000000 +0000
+++ interface/server_c.c
@@ -58,11 +58,7 @@
 #endif
 #include <signal.h>
 
-#ifdef HAVE_SYS_SOUNDCARD_H
-#include <sys/soundcard.h>
-#else
 #include "server_defs.h"
-#endif /* HAVE_SYS_SOUNDCARD_H */
 
 #include "timidity.h"
 #include "common.h"
