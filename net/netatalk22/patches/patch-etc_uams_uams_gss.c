$NetBSD: patch-etc_uams_uams_gss.c,v 1.1 2014/06/11 11:03:56 hauke Exp $

Dont override the value that recent Heimdal's set.

--- etc/uams/uams_gss.c.orig	2011-07-22 04:30:42.000000000 +0000
+++ etc/uams/uams_gss.c
@@ -64,8 +64,10 @@ char *strchr (), *strrchr ();
 /* We work around something I don't entirely understand... */
 /* BF: This is a Heimdal/MIT compatibility fix */
 #ifndef HAVE_GSS_C_NT_HOSTBASED_SERVICE
+#ifndef GSS_C_NT_HOSTBASED_SERVICE
 #define GSS_C_NT_HOSTBASED_SERVICE gss_nt_service_name
 #endif
+#endif
 
 #ifdef MIN
 #undef MIN
