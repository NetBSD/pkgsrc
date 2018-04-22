$NetBSD: patch-src_slurmd_slurmstepd_io.c,v 1.1 2018/04/22 21:31:09 bacon Exp $

# Portability

--- src/slurmd/slurmstepd/io.c.orig	2018-01-05 23:43:03.000000000 +0000
+++ src/slurmd/slurmstepd/io.c
@@ -45,6 +45,7 @@
 #endif
 
 #ifdef HAVE_UTMP_H
+#  include <time.h>
 #  include <utmp.h>
 #endif
 
