$NetBSD: patch-src_plugins_acct__gather__filesystem_lustre_acct__gather__filesystem__lustre.c,v 1.2 2014/03/19 22:05:39 asau Exp $

--- src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c.orig	2013-12-23 19:38:25.000000000 +0000
+++ src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c
@@ -49,6 +49,9 @@
 #include <getopt.h>
 #include <netinet/in.h>
 
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+#include <limits.h>	/* PATH_MAX */
+#endif
 
 #include "src/common/slurm_xlator.h"
 #include "src/common/slurm_acct_gather_filesystem.h"
