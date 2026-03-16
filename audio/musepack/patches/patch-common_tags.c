$NetBSD: patch-common_tags.c,v 1.1 2026/03/16 12:15:01 nia Exp $

Fix implicit function declarations.

--- common/tags.c.orig	2026-03-16 12:06:30.777895087 +0000
+++ common/tags.c
@@ -23,6 +23,7 @@
 
 // #include "mpcenc.h"
 #include <stdio.h>
+#include <string.h>
 #include <mpc/mpc_types.h>
 
 #ifdef _WIN32
