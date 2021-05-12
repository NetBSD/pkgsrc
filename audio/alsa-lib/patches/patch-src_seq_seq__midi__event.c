$NetBSD: patch-src_seq_seq__midi__event.c,v 1.2 2021/05/12 14:12:13 ryoon Exp $

--- src/seq/seq_midi_event.c.orig	2020-06-29 10:51:08.000000000 +0000
+++ src/seq/seq_midi_event.c
@@ -28,7 +28,7 @@
  *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include "local.h"
 
 #ifndef DOC_HIDDEN
