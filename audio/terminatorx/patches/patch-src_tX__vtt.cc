$NetBSD: patch-src_tX__vtt.cc,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_vtt.cc.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/tX_vtt.cc
@@ -26,7 +26,7 @@
 */
 
 #include "tX_vtt.h"
-#include "malloc.h"
+#include <stdlib.h>
 #include "tX_global.h"
 #include "tX_maingui.h"
 #include "tX_sequencer.h"
