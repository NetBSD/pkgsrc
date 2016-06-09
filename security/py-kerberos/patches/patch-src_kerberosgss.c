$NetBSD: patch-src_kerberosgss.c,v 1.1 2016/06/09 02:06:18 markd Exp $

Support heimdal

--- src/kerberosgss.c.orig	2016-01-25 17:51:33.000000000 +0000
+++ src/kerberosgss.c
@@ -43,7 +43,7 @@ char* server_principal_details(const cha
     int code;
     krb5_context kcontext;
     krb5_keytab kt = NULL;
-    krb5_kt_cursor cursor = NULL;
+    krb5_kt_cursor cursor;
     krb5_keytab_entry entry;
     char* pname = NULL;
     
@@ -67,7 +67,7 @@ char* server_principal_details(const cha
             KrbException_class,
             Py_BuildValue("((s:i))", "Cannot get default keytab", code)
         );
-        goto end;
+        goto end1;
     }
     
     if ((code = krb5_kt_start_seq_get(kcontext, kt, &cursor))) {
@@ -77,7 +77,7 @@ char* server_principal_details(const cha
                 "((s:i))", "Cannot get sequence cursor from keytab", code
             )
         );
-        goto end;
+        goto end1;
     }
     
     while ((code = krb5_kt_next_entry(kcontext, kt, &entry, &cursor)) == 0) {
@@ -115,9 +115,8 @@ char* server_principal_details(const cha
     }
     
 end:
-    if (cursor) {
-        krb5_kt_end_seq_get(kcontext, kt, &cursor);
-    }
+    krb5_kt_end_seq_get(kcontext, kt, &cursor);
+end1:
     if (kt) {
         krb5_kt_close(kcontext, kt);
     }
