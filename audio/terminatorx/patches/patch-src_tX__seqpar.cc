$NetBSD: patch-src_tX__seqpar.cc,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/tX_seqpar.cc.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/tX_seqpar.cc
@@ -27,7 +27,7 @@
 #include "tX_maingui.h"
 #include "tX_sequencer.h"
 #include "tX_vtt.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
