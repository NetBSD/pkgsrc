$NetBSD: patch-src_tX__vtt.cc,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_vtt.cc.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_vtt.cc
@@ -28,7 +28,7 @@
 #include "tX_vtt.h"
 #include "tX_global.h"
 #include <stdio.h>
-#include "malloc.h"
+#include <stdlib.h>
 #include <math.h>
 #include "tX_mastergui.h"
 #include "tX_sequencer.h"
