$NetBSD: patch-src_mpeg2dec_subspic.c,v 1.1 2026/03/18 14:38:19 nia Exp $

Fix implicit function declarations.

--- src/mpeg2dec/subspic.c.orig	2026-03-18 14:12:25.903199298 +0000
+++ src/mpeg2dec/subspic.c
@@ -31,6 +31,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "config.h"
 #include "global.h"
