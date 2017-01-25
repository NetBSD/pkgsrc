$NetBSD: patch-screen.c,v 1.3 2017/01/25 01:17:16 maya Exp $

Use standard headers.
Don't open user-supplied paths as root.

--- screen.c.orig	2017-01-17 19:28:29.000000000 +0000
+++ screen.c
@@ -88,6 +88,8 @@
 # include <langinfo.h>
 #endif
 
+#include <limits.h>
+
 #include "screen.h"
 #ifdef HAVE_BRAILLE
 # include "braille.h"
@@ -674,11 +676,17 @@ int main(int ac, char** av)
               if (strlen(screenlogfile) > PATH_MAX)
                 Panic(0, "-L: logfile name too long. (max. %d char)", PATH_MAX);
 
+	      int issetugid = geteuid() == 0;
+
+	      if (issetugid && seteuid(getuid()) < 0)
+		Panic(0, "setuid 1");
               FILE *w_check;
               if ((w_check = fopen(screenlogfile, "w")) == NULL)
                 Panic(0, "-L: logfile name access problem");
               else
                 fclose(w_check);
+	      if (issetugid && seteuid(0) < 0)
+		Panic(0, "setuid 2");
             }
             nwin_options.Lflag = 1;
             break;
