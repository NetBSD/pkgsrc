$NetBSD: patch-randnum.c,v 1.1 2025/08/01 08:13:09 jperkin Exp $

https://github.com/tytso/pwgen/commit/1459a31e07fa208cddb2c4f3f72071503c37b8bc

--- randnum.c.orig	2025-08-01 08:07:42.948068937 +0000
+++ randnum.c
@@ -18,20 +18,13 @@
 
 #include "pwgen.h"
 
-#ifdef HAVE_DRAND48
-extern double drand48(void);
-#endif
-
 static int get_random_fd(void);
 
-/* Borrowed/adapted from e2fsprogs's UUID generation code */
 static int get_random_fd()
 {
-	struct timeval	tv;
 	static int	fd = -2;
 
 	if (fd == -2) {
-		gettimeofday(&tv, 0);
 		fd = open("/dev/urandom", O_RDONLY);
 		if (fd == -1)
 			fd = open("/dev/random", O_RDONLY | O_NONBLOCK);
