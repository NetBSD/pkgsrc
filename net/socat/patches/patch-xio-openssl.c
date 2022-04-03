$NetBSD: patch-xio-openssl.c,v 1.1 2022/04/03 10:29:41 riastradh Exp $

Fix ctype(3) abuse.

--- xio-openssl.c.orig	2021-01-03 18:23:22.000000000 +0000
+++ xio-openssl.c
@@ -1505,7 +1505,7 @@ static int openssl_delete_cert_info(void
    progname = diag_get_string('p');
    envprefix[0] = '\0'; strncat(envprefix, progname, XIO_ENVNAMELEN-1);
    l = strlen(envprefix);
-   for (i = 0; i < l; ++i)  envprefix[i] = toupper(envprefix[i]);
+   for (i = 0; i < l; ++i)  envprefix[i] = toupper((unsigned char)envprefix[i]);
    strncat(envprefix+l, "_OPENSSL_", XIO_ENVNAMELEN-l-1);
 
 #if HAVE_VAR_ENVIRON
