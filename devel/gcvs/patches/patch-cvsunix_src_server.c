$NetBSD: patch-cvsunix_src_server.c,v 1.1 2011/12/23 01:12:35 joerg Exp $

--- cvsunix/src/server.c.orig	2011-12-22 23:36:59.000000000 +0000
+++ cvsunix/src/server.c
@@ -57,10 +57,6 @@ static Key_schedule sched;
 #include <gssapi/gssapi_generic.h>
 #endif
 
-#ifndef HAVE_GSS_C_NT_HOSTBASED_SERVICE
-#define GSS_C_NT_HOSTBASED_SERVICE gss_nt_service_name
-#endif
-
 /* We use Kerberos 5 routines to map the GSSAPI credential to a user
    name.  */
 #include <krb5.h>
