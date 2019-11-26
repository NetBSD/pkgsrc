$NetBSD: patch-src_sljit_sljitProtExecAllocator.c,v 1.2 2019/11/26 10:22:37 wiz Exp $

NetBSD does not have secure_getenv.
https://bugs.exim.org/show_bug.cgi?id=2469

--- src/sljit/sljitProtExecAllocator.c.orig	2017-02-15 17:24:58.000000000 +0000
+++ src/sljit/sljitProtExecAllocator.c
@@ -97,7 +97,9 @@ struct chunk_header {
 #endif
 
 int mkostemp(char *template, int flags);
+#if HAVE_SECURE_GETENV
 char *secure_getenv(const char *name);
+#endif
 
 static SLJIT_INLINE int create_tempfile(void)
 {
@@ -124,7 +126,11 @@ static SLJIT_INLINE int create_tempfile(
 	tmp_name_len = 4;
 #endif
 
+#if HAVE_SECURE_GETENV
 	dir = secure_getenv("TMPDIR");
+#else
+	dir = getenv("TMPDIR");
+#endif
 	if (dir) {
 		len = strlen(dir);
 		if (len > 0 && len < sizeof(tmp_name)) {
