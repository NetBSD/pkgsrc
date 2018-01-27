$NetBSD: patch-options.c,v 1.1 2018/01/27 04:21:18 snj Exp $

Fix CVE-2018-5764.  Patch from:

https://git.samba.org/rsync.git/?p=rsync.git;a=commitdiff;h=7706303828fcde524222babb2833864a4bd09e07

--- options.c.orig	2018-01-26 20:08:22.204810417 -0800
+++ options.c	2018-01-26 20:09:37.250284871 -0800
@@ -1294,6 +1294,7 @@ int parse_arguments(int *argc_p, const c
 	const char *arg, **argv = *argv_p;
 	int argc = *argc_p;
 	int opt;
+	int orig_protect_args = protect_args;
 
 	if (ref && *ref)
 		set_refuse_options(ref);
@@ -1903,6 +1904,10 @@ int parse_arguments(int *argc_p, const c
 	if (fuzzy_basis > 1)
 		fuzzy_basis = basis_dir_cnt + 1;
 
+	/* Don't let the client reset protect_args if it was already processed */
+	if (orig_protect_args == 2 && am_server)
+		protect_args = orig_protect_args;
+
 	if (protect_args == 1 && am_server)
 		return 1;
 
