$NetBSD: patch-src_edit.c,v 1.1 2025/11/30 15:30:03 martin Exp $

add missing include

--- src/edit.c.orig	2000-01-06 07:11:09.000000000 +0100
+++ src/edit.c	2025-11-30 16:24:55.358573723 +0100
@@ -2,6 +2,7 @@
 
 #include <stdio.h>
 #include <unistd.h>
+#include <string.h>
 #include "scav.h"
 #include "edit.h"
 #include "x.h"
