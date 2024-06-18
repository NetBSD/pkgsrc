$NetBSD: patch-texk_web2c_synctexdir_synctex__parser__utils.c,v 1.1 2024/06/18 09:39:40 markd Exp $

include <time.h> for time_t

--- texk/web2c/synctexdir/synctex_parser_utils.c.orig	2023-02-23 14:01:33.000000000 +0000
+++ texk/web2c/synctexdir/synctex_parser_utils.c
@@ -48,6 +48,7 @@
 
 #include <limits.h>
 #include <ctype.h>
+#include <time.h>
 
 #include <sys/stat.h>
 
