$NetBSD: patch-src_tX__audiofile.cc,v 1.1 2019/10/05 12:09:26 nia Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_audiofile.cc.orig	2016-07-24 14:24:08.000000000 +0000
+++ src/tX_audiofile.cc
@@ -30,7 +30,7 @@
 #include "tX_audiofile.h"
 
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "wav_file.h"
 #include "tX_loaddlg.h"
 #include "tX_endian.h"
