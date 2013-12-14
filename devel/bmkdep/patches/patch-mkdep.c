$NetBSD: patch-mkdep.c,v 1.3 2013/12/14 17:56:22 cheusov Exp $

For better portability
--- mkdep.c.orig	2013-10-09 14:38:38.000000000 +0000
+++ mkdep.c
@@ -33,7 +33,6 @@
 #include "nbtool_config.h"
 #endif
 
-#include <sys/cdefs.h>
 #if !defined(lint)
 __COPYRIGHT("@(#) Copyright (c) 1999 The NetBSD Foundation, Inc.\
  All rights reserved.");
@@ -48,15 +47,28 @@ __RCSID("$NetBSD: mkdep.c,v 1.43 2013/03
 #include <fcntl.h>
 #include <getopt.h>
 #include <locale.h>
+
+#ifndef __sun
 #include <paths.h>
 #define _WITH_DPRINTF
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "findcc.h"
 
+#ifndef _PATH_TMP
+#define _PATH_TMP "/tmp"
+#endif
+
+#ifndef _PATH_DEFPATH
+#define _PATH_DEFPATH "/usr/bin:/bin:/usr/local/bin"
+#endif
+
 typedef struct opt opt_t;
 struct opt {
 	opt_t	*left;
@@ -89,13 +101,13 @@ deconst(const void *p)
 	return (const char *)p - (const char *)0 + (char *)0;
 }
 
-__dead2 static void
+static void
 usage(void)
 {
 	(void)fprintf(stderr,
 	    "usage: %s [-aDdiopqv] [-f file] [-P prefix] [-s suffixes] "
 	    "-- [flags] file ...\n",
-	    getprogname());
+	    "bmkdep");
 	exit(EXIT_FAILURE);
 }
 
@@ -229,12 +241,12 @@ main(int argc, char **argv)
 	const char *prefix = NULL;
 	const char *suffixes = NULL, *s;
 	suff_list_t *suff_list = NULL, *sl;
+	char incl [PATH_MAX+100];
 
 	suf = NULL;		/* XXXGCC -Wuninitialized [sun2] */
 	sl = NULL;		/* XXXGCC -Wuninitialized [sun2] */
 
 	setlocale(LC_ALL, "");
-	setprogname(argv[0]);
 
 	aflag = O_WRONLY | O_APPEND | O_CREAT | O_TRUNC;
 	dflag = 0;
@@ -329,8 +341,14 @@ main(int argc, char **argv)
 			} else
 				fname = *argv++;
 			if (iflag) {
+#ifdef _WITH_DPRINTF
 				if (dprintf(dependfile, ".-include \"%s\"\n",
 				    fname) < 0)
+#else
+				snprintf (incl, sizeof (incl),
+				    ".-include \"%s\"\n", fname);
+				if (write(dependfile, incl, strlen(incl)) < 0)
+#endif
 					goto wrerror;
 				continue;
 			}
