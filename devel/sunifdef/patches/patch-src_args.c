$NetBSD: patch-src_args.c,v 1.1 2013/04/14 01:36:50 dholland Exp $

- Isolate this file's private getopt implementation from the system
one, as on some platforms (e.g. Solaris) the system one appears and
provides incompatible declarations.

--- src/args.c~	2008-01-22 20:11:22.000000000 +0000
+++ src/args.c
@@ -49,6 +49,14 @@
 #include <string.h>
 #include <stdarg.h>
 
+/*
+ * In case stdio.h brings in the system getopt declarations
+ */
+#define optind myoptind
+#define optopt myoptopt
+#define optarg myoptarg
+#define getopt mygetopt
+#define getopt_long mygetopt_long
 
 /*!\ingroup args_module args_interface args_internals
  *\file args.c
