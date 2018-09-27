$NetBSD: patch-tgl_tl-parser_tl-parser.c,v 1.1 2018/09/27 19:53:07 tnn Exp $

error: %m is only allowed in syslog(3) like functions

--- tgl/tl-parser/tl-parser.c.orig	2015-10-17 13:33:25.000000000 +0000
+++ tgl/tl-parser/tl-parser.c
@@ -32,6 +32,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
+#include <errno.h>
 #include <string.h>
 #include <time.h>
 #include <zlib.h>
@@ -333,7 +334,7 @@ int expect (char *s) {
 struct parse *tl_init_parse_file (const char *fname) {
   int fd = open (fname, O_RDONLY);
   if (fd < 0) {
-    fprintf (stderr, "Error %m\n");
+    fprintf (stderr, "Error %s\n", strerror(errno));
     assert (0);
     return 0;
   }
