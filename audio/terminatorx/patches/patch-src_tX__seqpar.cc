$NetBSD: patch-src_tX__seqpar.cc,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_seqpar.cc.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_seqpar.cc
@@ -28,7 +28,7 @@
 #include "tX_sequencer.h"
 #include "tX_extdial.h"
 #include "tX_engine.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #define TX_SEQPAR_DEFAULT_SCALE 0.05
