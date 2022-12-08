$NetBSD: patch-we__prog.c,v 1.1 2022/12/08 10:31:08 vins Exp $

Fix implicit declaration warnings.

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
