$NetBSD: patch-ImmModules_TL-1_xl__mfile.c,v 1.1 2011/11/26 17:13:30 joerg Exp $

--- ImmModules/TL-1/xl_mfile.c.orig	2011-11-26 03:23:49.000000000 +0000
+++ ImmModules/TL-1/xl_mfile.c
@@ -1,5 +1,6 @@
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <memwatch.h>
 
 typedef struct MemFile_handle
