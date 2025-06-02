$NetBSD: patch-we__prog.c,v 1.2 2025/06/02 12:54:30 vins Exp $

* Fix implicit declaration warnings.
* Fix format-security warning around improper printf() usage.

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
@@ -1477,7 +1484,7 @@ int e_system(char *estr, ECNT *cn)
  ret = system(estr);
  if (!WpeIsXwin())
  {
-  printf(e_msg[ERR_HITCR]);
+  printf("%s",e_msg[ERR_HITCR]);
   fflush(stdout);
   fk_getch();
  }
