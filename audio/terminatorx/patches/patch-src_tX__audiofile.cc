$NetBSD: patch-src_tX__audiofile.cc,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_audiofile.cc.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/tX_audiofile.cc
@@ -32,7 +32,7 @@
 #include "tX_endian.h"
 #include "tX_loaddlg.h"
 #include "wav_file.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #define __STDC_FORMAT_MACROS
