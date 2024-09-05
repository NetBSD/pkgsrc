$NetBSD: patch-src_sayaka.c,v 1.1 2024/09/05 14:57:29 tsutsui Exp $

- pull an upstream fix
 https://github.com/isaki68k/sayaka/commit/e0784dddc

--- src/sayaka.c.orig	2024-09-04 16:33:42.885686709 +0000
+++ src/sayaka.c
@@ -148,7 +148,7 @@ static const struct option longopts[] = 
 	{ "ipv6",			no_argument,		NULL,	OPT_ipv6 },
 	{ "jis",			no_argument,		NULL,	OPT_jis },
 	{ "light",			no_argument,		NULL,	OPT_light },
-	{ "local",			required_argument,	NULL,	'l' },
+	{ "local",			no_argument,		NULL,	'l' },
 	{ "mathalpha",		no_argument,		NULL,	OPT_mathalpha },
 	{ "max-image-cols",	required_argument,	NULL,	OPT_max_image_cols },
 	{ "misskey",		no_argument,		NULL,	OPT_misskey },
