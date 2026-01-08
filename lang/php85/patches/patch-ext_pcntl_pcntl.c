$NetBSD: patch-ext_pcntl_pcntl.c,v 1.1 2026/01/08 13:38:00 taca Exp $

Use proper type for wait6(2).

--- ext/pcntl/pcntl.c.orig	2025-12-16 15:59:07.000000000 +0000
+++ ext/pcntl/pcntl.c
@@ -437,8 +437,8 @@ PHP_FUNCTION(pcntl_waitid)
 		}
 		struct rusage rusage;
 # if defined(HAVE_WAIT6) /* FreeBSD */
-		struct __wrusage wrusage;
-		memset(&wrusage, 0, sizeof(struct __wrusage));
+		struct wrusage wrusage;
+		memset(&wrusage, 0, sizeof(struct wrusage));
 		pid_t pid = wait6((idtype_t) idtype, (id_t) id, &status, (int) options, &wrusage, &siginfo);
 		status = pid > 0 ? 0 : pid;
 		memcpy(&rusage, &wrusage.wru_self, sizeof(struct rusage));
