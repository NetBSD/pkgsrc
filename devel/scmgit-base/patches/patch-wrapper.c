$NetBSD: patch-wrapper.c,v 1.1 2013/06/07 13:05:42 gdt Exp $

git's wrapper around mkstemp assumes that the libc function will not
modify the argument when the call fails.  This causes one of git's
tests to fail.  This patch is from Junio C. Hamano, and will likely be
included in future versions of git.

--- wrapper.c.orig	2012-11-26 03:18:01.000000000 +0000
+++ wrapper.c
@@ -229,7 +229,7 @@ int xmkstemp(char *template)
 		int saved_errno = errno;
 		const char *nonrelative_template;
 
-		if (!template[0])
+		if (strlen(template) != strlen(origtemplate))
 			template = origtemplate;
 
 		nonrelative_template = absolute_path(template);
