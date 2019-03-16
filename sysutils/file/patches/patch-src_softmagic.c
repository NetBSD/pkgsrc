$NetBSD: patch-src_softmagic.c,v 1.5 2019/03/16 10:50:31 leot Exp $

Fix functionality under NetBSD-current after format check change
https://mail-index.netbsd.org/source-changes/2017/12/11/msg090400.html

--- src/softmagic.c.orig	2019-02-20 02:35:27.000000000 +0000
+++ src/softmagic.c
@@ -147,6 +147,8 @@ private const char * __attribute__((__fo
 file_fmtcheck(struct magic_set *ms, const char *desc, const char *def,
 	const char *file, size_t line)
 {
+	if (strchr(desc, '%') == NULL)
+		return desc;
 	const char *ptr = fmtcheck(desc, def);
 	if (ptr == def)
 		file_magerror(ms,
