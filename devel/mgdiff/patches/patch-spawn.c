$NetBSD: patch-spawn.c,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- spawn.c.orig	1994-05-19 02:01:23.000000000 +0000
+++ spawn.c
@@ -1,5 +1,5 @@
-#ifndef lint
-static char rcsid[] = "spawn.c,v 2.0 1994/05/19 02:01:23 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "spawn.c,v 2.0 1994/05/19 02:01:23 dan Exp";
 #endif
 
 /*
@@ -35,8 +35,32 @@ static char rcsid[] = "spawn.c,v 2.0 199
 #include <stdlib.h>
 #include <errno.h>
 
+#include <X11/Intrinsic.h>
+
+#include "mgdiff.h"
+#include "externs.h"
+
 #define BLOCKSIZE 10
 
+static inline void* xmalloc(size_t size)
+{
+    void *ret = malloc(size);
+    if (!ret) {
+	perror("malloc");
+	exit(1);
+    }
+    return ret;
+}
+static inline void* xrealloc(void *ptr, size_t size)
+{
+    void *ret = realloc(ptr, size);
+    if (!ret) {
+	perror("realloc");
+	exit(1);
+    }
+    return ret;
+}
+
 /* 
  * run a program with command line arguments and two pathname 
  * arguments via fork/exec and return a pipe file descriptor into 
@@ -86,26 +110,26 @@ FILE *spawn_diff (char *prog, char *args
 
 	argc = 0;
 	count = BLOCKSIZE;
-	argv = (char **) malloc (sizeof (char *) * BLOCKSIZE);
+	argv = (char **) xmalloc (sizeof (char *) * BLOCKSIZE);
 	argv[argc++] = prog;
 
 	for (ptr = strtok (args, " \t"); ptr; ptr = strtok (NULL, " \t")) {
 	    if (argc >= count) {
-		argv = (char **) realloc (argv, sizeof (char *) * BLOCKSIZE);
+		argv = (char **) xrealloc (argv, sizeof (char *) * BLOCKSIZE);
 		count += BLOCKSIZE;
 	    }
 	    argv[argc++] = strdup (ptr);
 	}
 
 	if ((argc + 3) >= count)
-	    argv = (char **) realloc (argv, sizeof (char *) * 3);
+	    argv = (char **) xrealloc (argv, sizeof (char *) * 3);
 
 	argv[argc++] = path1;
 	argv[argc++] = path2;
 	argv[argc++] = NULL;
 
 	if (execvp (prog, argv) == -1) {
-	    (void) sprintf (buffer, "%s: %s: %s", progname, "exec", prog);
+	    (void) snprintf (buffer, sizeof (buffer), "%s: %s: %s", progname, "exec", prog);
 	    perror (buffer);
 	    exit (2);
 	}
@@ -131,4 +155,5 @@ FILE *spawn_diff (char *prog, char *args
 	break;
     }
     /* NOTREACHED */
+    return NULL;
 }
