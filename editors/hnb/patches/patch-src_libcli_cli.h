$NetBSD: patch-src_libcli_cli.h,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/libcli/cli.h.orig	2003-03-12 12:20:05.000000000 +0000
+++ src/libcli/cli.h
@@ -29,6 +29,9 @@
 #define LIBCLI_H
 
 #include <stdarg.h>
+#include <stdint.h>
+
+#define PTR_TO_UINT64(x) (uint64_t)(uintptr_t)(x)
 
 void argv_sanity(void);
 
@@ -41,7 +44,7 @@ void cli_cleanup(void);
 void
 cli_add_item (char *name,
 		  int *integer, char *string,
-		  int (*func) (int argc,char **argv, void *data), char *usage);
+		  uint64_t (*func) (int argc,char **argv, void *data), char *usage);
 
 #define cli_add_int(name,integer,usage)\
 	cli_add_item (name, integer, NULL, NULL, usage)
@@ -52,10 +52,10 @@
 #define cli_add_command(name,func,usage) \
 	cli_add_item(name, NULL, NULL, func, usage)
 
-int cli_load_file(char *filename);
+uint64_t cli_load_file(char *filename);
 
 char *cli_complete (const char *commandline);	/* returns a completed commandline */
-int cli_docmd (char *commandline, void *data);	/* run commandline */
+uint64_t cli_docmd (char *commandline, void *data);	/* run commandline */
 
 
 extern void (*cli_outfun) (char *);	/* the outputting function 
