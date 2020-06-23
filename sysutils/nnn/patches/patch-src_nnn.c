$NetBSD: patch-src_nnn.c,v 1.2 2020/06/23 23:32:30 sjmulder Exp $

 - Always use builtin alloca() on GCC to fix NetBSD/arm64 build.

   https://github.com/jarun/nnn/pull/666

 - Wrap FILE_MIME_OPTS use in check, since it's not defined (at the top
   of nnn.c) for Illumos which doesn't have such an option.

   https://github.com/jarun/nnn/pull/622

--- src/nnn.c.orig	2020-06-23 22:41:07.232929706 +0000
+++ src/nnn.c
@@ -90,9 +90,6 @@
 #include <signal.h>
 #include <stdarg.h>
 #include <stdlib.h>
-#ifdef __sun
-#include <alloca.h>
-#endif
 #include <string.h>
 #include <strings.h>
 #include <time.h>
@@ -103,6 +100,15 @@
 #include <ftw.h>
 #include <wchar.h>
 
+#if !defined(alloca) && defined(__GNUC__)
+/*
+ * GCC doesn't expand alloca() to __builtin_alloca() in standards mode
+ * (-std=...) and not all standard libraries do or supply it, e.g.
+ * NetBSD/arm64 so explicitly use the builtin.
+ */
+#define alloca(size) __builtin_alloca(size)
+#endif
+
 #include "nnn.h"
 #include "dbg.h"
 
@@ -3689,9 +3695,11 @@ static bool show_stats(const char *fpath
 			}
 			fprintf(fp, " %s\n  ", begin);
 
+#ifdef FILE_MIME_OPTS
 			/* Show the file mime type */
 			get_output(g_buf, CMD_LEN_MAX, "file", FILE_MIME_OPTS, fpath, FALSE);
 			fprintf(fp, "%s", g_buf);
+#endif
 		}
 	}
 
