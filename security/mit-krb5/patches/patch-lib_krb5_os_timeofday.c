$NetBSD: patch-lib_krb5_os_timeofday.c,v 1.1 2018/05/25 13:46:40 jperkin Exp $

Avoid bogus -Wuninitialized warning.

--- lib/krb5/os/timeofday.c.orig	2017-09-25 16:29:00.000000000 +0000
+++ lib/krb5/os/timeofday.c
@@ -54,7 +54,7 @@ krb5_timeofday(krb5_context context, reg
 krb5_error_code KRB5_CALLCONV
 krb5_check_clockskew(krb5_context context, krb5_timestamp date)
 {
-    krb5_timestamp currenttime;
+    krb5_timestamp currenttime = 0;
     krb5_error_code retval;
 
     retval = krb5_timeofday(context, &currenttime);
