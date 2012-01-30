$NetBSD: patch-lib_fexec.c,v 1.1 2012/01/30 03:43:58 sbd Exp $

Rename custom function "fexecve", which conflicts with glibc's fexecve(3),
to schily_fexecve.

--- lib/fexec.c.orig	2002-06-08 16:45:11.000000000 +0000
+++ lib/fexec.c
@@ -161,7 +161,7 @@ int fexecle(name, in, out, err, va_alist
 	} while (p != NULL);
 	va_end(args);
 
-	ret = fexecve(name, in, out, err, av, env);
+	ret = schily_fexecve(name, in, out, err, av, env);
 	if (av != xav)
 		free(av);
 	return (ret);
@@ -174,10 +174,10 @@ int fexecv(name, in, out, err, ac, av)
 	char *av[];
 {
 	av[ac] = NULL;			/*  force list to be null terminated */
-	return fexecve (name, in, out, err, av, environ);
+	return schily_fexecve (name, in, out, err, av, environ);
 }
 
-int fexecve(name, in, out, err, av, env)
+int schily_fexecve(name, in, out, err, av, env)
 	const char *name;
 	FILE *in, *out, *err;
 	char * const av[], * const env[];
