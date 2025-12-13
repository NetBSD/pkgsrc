$NetBSD: patch-tcptrace.c,v 1.1 2025/12/13 16:42:03 vins Exp $

--- tcptrace.c.orig	2004-10-01 21:42:34.000000000 +0000
+++ tcptrace.c
@@ -639,7 +639,7 @@ Dump File Names\n\
 	char buf[256];		/* plenty large, but checked below with strncpy */
 	struct ext_var_op *pvop = &extended_vars[i];
 	strncpy(buf,pvop->var_optname,sizeof(buf)-10);
-	strcat(buf,"=\"STR\"");
+	strncat(buf,"=\"STR\"", sizeof(buf));
 	fprintf(stderr,"  --%-20s %s (default: '%s')\n",
 		buf,
 		pvop->var_descr,
