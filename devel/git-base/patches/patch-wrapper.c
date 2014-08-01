$NetBSD: patch-wrapper.c,v 1.2 2014/08/01 19:18:39 schmonz Exp $

git's wrapper around mkstemp assumes that the libc function will not
modify the argument when the call fails.  This causes one of git's
tests to fail.  This patch is from Junio C. Hamano, and will likely be
included in future versions of git.

--- wrapper.c.orig	2014-05-30 21:38:10.000000000 +0000
+++ wrapper.c
@@ -378,7 +378,7 @@ int xmkstemp_mode(char *template, int mo
 		int saved_errno = errno;
 		const char *nonrelative_template;
 
-		if (!template[0])
+		if (strlen(template) != strlen(origtemplate))
 			template = origtemplate;
 
 		nonrelative_template = absolute_path(template);
