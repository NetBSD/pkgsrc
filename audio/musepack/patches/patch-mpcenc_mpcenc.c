$NetBSD: patch-mpcenc_mpcenc.c,v 1.1 2026/03/16 12:15:02 nia Exp $

Fix implicit function declarations.

--- mpcenc/mpcenc.c.orig	2026-03-16 11:50:32.269692588 +0000
+++ mpcenc/mpcenc.c
@@ -23,6 +23,7 @@
 #include <memory.h>
 #include <time.h>
 #include <errno.h>
+#include <string.h>
 
 #include "mpcenc.h"
 #include <mpc/mpcmath.h>
