$NetBSD: patch-src_pl-funcs.h,v 1.2 2014/05/28 10:29:12 markd Exp $

Don't change visibility of a system prototype.

--- src/pl-funcs.h.orig	2014-04-25 14:06:38.000000000 +0000
+++ src/pl-funcs.h
@@ -347,7 +347,9 @@ COMMON(void)		setOSPrologFlags(void);
 COMMON(void)		RemoveTemporaryFiles(void);
 COMMON(bool)		OpenStream(int fd);
 COMMON(char *)		expandVars(const char *pattern, char *expanded, int len);
+#ifndef HAVE_GETWD
 COMMON(char *)		getwd(char *buf);
+#endif
 COMMON(char *)		AbsoluteFile(const char *spec, char *path);
 COMMON(int)		IsAbsolutePath(const char *spec);
 COMMON(char *)		BaseName(const char *f);
