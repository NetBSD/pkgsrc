$NetBSD: patch-src_core_g2_gwc.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/g2/gwc.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/g2/gwc.c
@@ -324,7 +324,7 @@ retry:
 	line = 0;
 	added = 0;
 
-	while (fgets(ARYLEN(tmp), in)) {
+	while (fgets(tmp, sizeof(tmp), in)) {
 		line++;
 
 		if (tmp[0] == '#')		/* Skip comments */
