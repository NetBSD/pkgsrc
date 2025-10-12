$NetBSD: patch-src_nav.c,v 1.1 2025/10/12 02:57:35 mrg Exp $

Include info.h and add a forward prototype.

--- src/nav.c.orig	2003-03-10 09:20:06.000000000 -0800
+++ src/nav.c	2025-10-11 19:44:51.178774901 -0700
@@ -41,6 +41,7 @@
 
 #include "dvdplay/dvdplay.h"
 #include "dvdplay/nav.h"
+#include "dvdplay/info.h"
 
 #include "tools.h"
 #include "command.h"
@@ -55,6 +56,8 @@ static int MouseButton   ( pci_t * p_pci
 static int NextDataPacket( const dvdplay_ptr dvdplay, byte_t** pp_buffer );
 static int ReadNav       ( dvdplay_ptr dvdplay, byte_t* p_buffer );
 
+int dvdplay_cmd( dvdplay_ptr dvdplay, vm_cmd_t *cmd );
+
 #define CELL \
     dvdplay->state.p_pgc->cell_playback[dvdplay->state.i_cellN - 1 ]
 
