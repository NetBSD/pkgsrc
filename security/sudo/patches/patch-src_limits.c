$NetBSD: patch-src_limits.c,v 1.2 2019/12/19 16:59:44 kim Exp $

* Disable RLIMIT_STACK on NetBSD, see https://gnats.netbsd.org/51158
* Indicate the name of the resource for which setrlimit fails.
* Simplify resource limit fallback logic a bit.
* Don't set the RLIMIT_STACK soft/hard limits to unlimited.
* macOS does not allow rlim_cur to be set to RLIM_INFINITY for RLIMIT_NOFILE.

--- src/limits.c.orig	2019-10-28 14:28:52.000000000 +0200
+++ src/limits.c	2019-12-19 18:52:11.232251175 +0200
@@ -37,28 +37,48 @@
 #ifdef __linux__
 # include <sys/prctl.h>
 #endif
+#include <limits.h>
 
 #include "sudo.h"
 
+#if defined(OPEN_MAX) && OPEN_MAX > 256
+# define SUDO_OPEN_MAX	OPEN_MAX
+#else
+# define SUDO_OPEN_MAX	256
+#endif
+
+/*
+ * macOS doesn't allow nofile soft limit to be infinite or
+ * the stack hard limit to be infinite.
+ * Linux containers have a problem with an infinite stack soft limit.
+ */
+static struct rlimit nofile_fallback = { SUDO_OPEN_MAX, RLIM_INFINITY };
+static struct rlimit stack_fallback = { 8192 * 1024, 65532 * 1024 };
+
 static struct saved_limit {
+    char *name;
     int resource;
     bool saved;
-    struct rlimit limit;
+    struct rlimit *fallback;
+    struct rlimit newlimit;
+    struct rlimit oldlimit;
 } saved_limits[] = {
 #ifdef RLIMIT_AS
-    { RLIMIT_AS },
+    { "RLIMIT_AS", RLIMIT_AS, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
 #endif
-    { RLIMIT_CPU },
-    { RLIMIT_DATA },
-    { RLIMIT_FSIZE },
-    { RLIMIT_NOFILE },
+    { "RLIMIT_CPU", RLIMIT_CPU, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
+    { "RLIMIT_DATA", RLIMIT_DATA, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
+    { "RLIMIT_FSIZE", RLIMIT_FSIZE, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
+    { "RLIMIT_NOFILE", RLIMIT_NOFILE, false, &nofile_fallback, { RLIM_INFINITY, RLIM_INFINITY } },
 #ifdef RLIMIT_NPROC
-    { RLIMIT_NPROC },
+    { "RLIMIT_NPROC", RLIMIT_NPROC, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
 #endif
 #ifdef RLIMIT_RSS
-    { RLIMIT_RSS },
+    { "RLIMIT_RSS", RLIMIT_RSS, false, NULL, { RLIM_INFINITY, RLIM_INFINITY } },
+#endif
+#ifndef __NetBSD__
+    { "RLIMIT_STACK", RLIMIT_STACK, false, &stack_fallback, { 8192 * 1024, RLIM_INFINITY } }
 #endif
-    { RLIMIT_STACK }
 };
 
 static struct rlimit corelimit;
@@ -160,21 +180,39 @@
 void
 unlimit_sudo(void)
 {
-    struct rlimit inf = { RLIM_INFINITY, RLIM_INFINITY };
     unsigned int idx;
+    int rc;
     debug_decl(unlimit_sudo, SUDO_DEBUG_UTIL)
 
     /* Set resource limits to unlimited and stash the old values. */
     for (idx = 0; idx < nitems(saved_limits); idx++) {
 	struct saved_limit *lim = &saved_limits[idx];
-	if (getrlimit(lim->resource, &lim->limit) == -1)
+	if (getrlimit(lim->resource, &lim->oldlimit) == -1)
 	    continue;
 	lim->saved = true;
-	if (setrlimit(lim->resource, &inf) == -1) {
-	    struct rlimit rl = lim->limit;
-	    rl.rlim_cur = rl.rlim_max;
-	    if (setrlimit(lim->resource, &rl) == -1)
-		sudo_warn("setrlimit(%d)", lim->resource);
+	if (lim->newlimit.rlim_cur != RLIM_INFINITY) {
+	    /* Don't reduce the soft resource limit. */
+	    if (lim->oldlimit.rlim_cur == RLIM_INFINITY ||
+		    lim->oldlimit.rlim_cur > lim->newlimit.rlim_cur)
+		lim->newlimit.rlim_cur = lim->oldlimit.rlim_cur;
+	}
+	if (lim->newlimit.rlim_max != RLIM_INFINITY) {
+	    /* Don't reduce the hard resource limit. */
+	    if (lim->oldlimit.rlim_max == RLIM_INFINITY ||
+		    lim->oldlimit.rlim_max > lim->newlimit.rlim_max)
+		lim->newlimit.rlim_max = lim->oldlimit.rlim_max;
+	}
+	if ((rc = setrlimit(lim->resource, &lim->newlimit)) == -1) {
+	    if (lim->fallback != NULL)
+		rc = setrlimit(lim->resource, lim->fallback);
+	    if (rc == -1) {
+		/* Try setting new rlim_cur to old rlim_max. */
+		lim->newlimit.rlim_cur = lim->oldlimit.rlim_max;
+		lim->newlimit.rlim_max = lim->oldlimit.rlim_max;
+		rc = setrlimit(lim->resource, &lim->newlimit);
+	    }
+	    if (rc == -1)
+		sudo_warn("setrlimit(%s)", lim->name);
 	}
     }
 
@@ -194,8 +232,8 @@
     for (idx = 0; idx < nitems(saved_limits); idx++) {
 	struct saved_limit *lim = &saved_limits[idx];
 	if (lim->saved) {
-	    if (setrlimit(lim->resource, &lim->limit) == -1)
-		sudo_warn("setrlimit(%d)", lim->resource);
+	    if (setrlimit(lim->resource, &lim->oldlimit) == -1)
+		sudo_warn("setrlimit(%s)", lim->name);
 	}
     }
     restore_coredump();
