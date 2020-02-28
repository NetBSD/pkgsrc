$NetBSD: patch-src_log.c,v 1.1 2020/02/28 17:52:13 gdt Exp $

G_CONST_RETURN has been deprecated for a long time.

Not yet reported upstream.

--- src/log.c.orig	2015-04-19 20:39:29.000000000 +0000
+++ src/log.c
@@ -455,7 +455,7 @@ savelog (gpointer arg, gchar * logfile, 
 {
 	LOGDB *lp;
 	gint i, j, k, pid, exported;
-	G_CONST_RETURN gchar *label;
+	const gchar *label;
 	gchar *pathstr;
 	item_t *sorteditems;
 	gint fields[QSO_FIELDS], widths[QSO_FIELDS];
