$NetBSD: patch-we__prog.c,v 1.3 2026/11/15 13:14:45 vins Exp $

Fix implicit declaration of print_to_end_of_buffer().

--- we_prog.c.orig	2005-07-07 01:53:09.000000000 +0000
+++ we_prog.c
@@ -8,6 +8,13 @@
 #include "edit.h"
 #include "WeExpArr.h"
 
+#ifndef __WE_PROG_H
+#define __WE_PROG_H
+
+int print_to_end_of_buffer(BUFFER *b, char *str, int wrap_limit);
+
+#endif
+
 #ifdef PROG
 
 #include <time.h>
