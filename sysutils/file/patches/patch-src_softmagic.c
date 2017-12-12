$NetBSD: patch-src_softmagic.c,v 1.3 2017/12/12 03:11:51 ryoon Exp $

Fix functionality under NetBSD-current after format check change
https://mail-index.netbsd.org/source-changes/2017/12/11/msg090400.html

--- src/softmagic.c.orig	2017-07-21 10:29:00.000000000 +0000
+++ src/softmagic.c
@@ -121,6 +121,8 @@ private const char * __attribute__((__fo
 file_fmtcheck(struct magic_set *ms, const struct magic *m, const char *def,
 	const char *file, size_t line)
 {
+	if (strchr(m->desc, '%') == NULL)
+		return m->desc;
 	const char *ptr = fmtcheck(m->desc, def);
 	if (ptr == def)
 		file_magerror(ms,
