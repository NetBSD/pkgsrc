$NetBSD: patch-src_mpeg2dec_getbits.c,v 1.1 2026/03/18 14:38:19 nia Exp $

Fix implicit function declarations.

--- src/mpeg2dec/getbits.c.orig	2026-03-18 14:14:13.753370963 +0000
+++ src/mpeg2dec/getbits.c
@@ -34,6 +34,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #include "config.h"
 #include "global.h"
