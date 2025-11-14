$NetBSD: patch-src_internal_fy-thread.c,v 1.1 2025/11/14 09:45:24 adam Exp $

getopt_long_only is not very portable; use getopt_long instead

--- src/internal/fy-thread.c.orig	2025-10-30 16:33:56.743298864 +0000
+++ src/internal/fy-thread.c
@@ -549,7 +549,7 @@ int main(int argc, char *argv[])
 	unsigned int num_threads = 0;
 	int exitcode = EXIT_FAILURE, opti;
 
-	while ((opt = getopt_long_only(argc, argv, "h", lopts, &lidx)) != -1) {
+	while ((opt = getopt_long(argc, argv, "h", lopts, &lidx)) != -1) {
 		switch (opt) {
 		case OPT_NUM_THREADS:
 			opti = atoi(optarg);
