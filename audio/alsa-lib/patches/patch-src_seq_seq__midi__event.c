$NetBSD: patch-src_seq_seq__midi__event.c,v 1.1 2014/03/25 23:06:07 asau Exp $

--- src/seq/seq_midi_event.c.orig	2009-12-16 15:18:51.000000000 +0000
+++ src/seq/seq_midi_event.c
@@ -28,7 +28,7 @@
  *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include "local.h"
 
 #ifndef DOC_HIDDEN
