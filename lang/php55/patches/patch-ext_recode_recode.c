$NetBSD: patch-ext_recode_recode.c,v 1.1 2016/07/24 13:38:54 jdolecek Exp $

program_name is expected variable, is required by recode 3.5 and recode 3.6 to actually work.

The config.m4 test for it is broken at least for some platforms -  it only tests if program without it compiles, but on Solaris and MacOS/Darwin at least it only fails when run.

--- ext/recode/recode.c.orig	2016-07-24 13:07:47.000000000 +0000
+++ ext/recode/recode.c
@@ -29,11 +29,8 @@
 
 #if HAVE_LIBRECODE
 
-/* For recode 3.5 */
-#if HAVE_BROKEN_RECODE
-extern char *program_name;
-char *program_name = "php";
-#endif
+extern const char *program_name;
+const char *program_name = "php";
 
 #ifdef HAVE_STDBOOL_H
 # include <stdbool.h>
