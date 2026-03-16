$NetBSD: patch-mpcenc_pipeopen.c,v 1.1 2026/03/16 12:15:02 nia Exp $

Fix implicit function declarations.

--- mpcenc/pipeopen.c.orig	2026-03-16 12:06:47.692953840 +0000
+++ mpcenc/pipeopen.c
@@ -18,6 +18,7 @@
 
 #include <mpc/mpc_types.h>
 #include <ctype.h>
+#include <string.h>
 
 #include "mpcenc.h"
 
