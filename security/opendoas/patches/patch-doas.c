$NetBSD: patch-doas.c,v 1.1 2021/01/29 07:53:38 jperkin Exp $

Fix for CVE-2019-25016 (Unsafe, incomplete PATH reset).

--- doas.c.orig	2020-11-14 15:44:04.000000000 +0000
+++ doas.c
@@ -386,6 +386,7 @@ main(int argc, char **argv)
 
 #ifdef HAVE_LOGIN_CAP_H
 	if (setusercontext(NULL, targpw, target, LOGIN_SETGROUP |
+	    LOGIN_SETPATH |
 	    LOGIN_SETPRIORITY | LOGIN_SETRESOURCES | LOGIN_SETUMASK |
 	    LOGIN_SETUSER) != 0)
 		errx(1, "failed to set user context for target");
@@ -396,6 +397,8 @@ main(int argc, char **argv)
 		err(1, "initgroups");
 	if (setresuid(target, target, target) != 0)
 		err(1, "setresuid");
+	if (setenv("PATH", safepath, 1) == -1)
+		err(1, "failed to set PATH '%s'", safepath);
 #endif
 
 	if (getcwd(cwdpath, sizeof(cwdpath)) == NULL)
