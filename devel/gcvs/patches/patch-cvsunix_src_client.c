$NetBSD: patch-cvsunix_src_client.c,v 1.1 2011/12/23 01:12:35 joerg Exp $

--- cvsunix/src/client.c.orig	2011-12-22 23:37:10.000000000 +0000
+++ cvsunix/src/client.c
@@ -87,10 +87,6 @@ static Key_schedule sched;
 #include <gssapi/gssapi_generic.h>
 #endif
 
-#ifndef HAVE_GSS_C_NT_HOSTBASED_SERVICE
-#define GSS_C_NT_HOSTBASED_SERVICE gss_nt_service_name
-#endif
-
 /* This is needed for GSSAPI encryption.  */
 static gss_ctx_id_t gcontext;
 
