$NetBSD: patch-lib_rnmt.c,v 1.1 2026/04/19 08:56:00 wiz Exp $

Fix pointer/value confusion.

--- lib/rnmt.c.orig	2026-04-19 08:51:39.365426497 +0000
+++ lib/rnmt.c
@@ -188,13 +188,13 @@ build_path(char **buf, size_t *remaining, const struct
 		return;
 
 	build_path(buf, remaining, lnc->lnc_plnc);
-	if (remaining == 0) {
+	if (*remaining == 0) {
 		return;
 	}
 	if (lnc->lnc_plnc != NULL) {
 		**buf = '/';
 		(*buf)++;
-		remaining--;
+		(*remaining)--;
 	}
 	len = lnc->lnc_nlen;
 	if (*remaining < len)
