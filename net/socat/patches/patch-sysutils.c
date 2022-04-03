$NetBSD: patch-sysutils.c,v 1.1 2022/04/03 10:29:41 riastradh Exp $

Fix ctype(3) abuse.

--- sysutils.c.orig	2021-01-03 18:23:22.000000000 +0000
+++ sysutils.c
@@ -745,7 +745,7 @@ int xiosetenv(const char *varname, const
    progname = diag_get_string('p');
    envname[0] = '\0'; strncat(envname, progname, XIO_ENVNAMELEN-1);
    l = strlen(envname);
-   for (i = 0; i < l; ++i)  envname[i] = toupper(envname[i]);
+   for (i = 0; i < l; ++i)  envname[i] = toupper((unsigned char)envname[i]);
    strncat(envname+l, "_", XIO_ENVNAMELEN-l-1);
    l += 1;
    strncat(envname+l, varname, XIO_ENVNAMELEN-l-1);
@@ -771,7 +771,7 @@ int xiosetenv2(const char *varname, cons
    l += 1;
    strncat(envname+l, varname2, XIO_ENVNAMELEN-l-1);
    l += strlen(envname+l);
-   for (i = 0; i < l; ++i)  envname[i] = toupper(envname[i]);
+   for (i = 0; i < l; ++i)  envname[i] = toupper((unsigned char)envname[i]);
    return _xiosetenv(envname, value, overwrite, sep);
 #  undef XIO_ENVNAMELEN
 }
@@ -799,7 +799,7 @@ int xiosetenv3(const char *varname, cons
    l += 1;
    strncat(envname+l, varname3, XIO_ENVNAMELEN-l-1);
    l += strlen(envname+l);
-   for (i = 0; i < l; ++i)  envname[i] = toupper(envname[i]);
+   for (i = 0; i < l; ++i)  envname[i] = toupper((unsigned char)envname[i]);
    return _xiosetenv(envname, value, overwrite, sep);
 #  undef XIO_ENVNAMELEN
 }
