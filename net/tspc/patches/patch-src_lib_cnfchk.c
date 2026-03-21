$NetBSD: patch-src_lib_cnfchk.c,v 1.1 2026/03/21 10:35:44 nia Exp $

Fix implicit declaration of string functions.

--- src/lib/cnfchk.c.orig	2026-03-21 10:13:05.037597336 +0000
+++ src/lib/cnfchk.c
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <memory.h>
+#include <string.h>
 
 #include "platform.h"
 
