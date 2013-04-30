$NetBSD: patch-kdc_do_tgs_req.c,v 1.1.2.2 2013/04/30 18:50:01 tron Exp $

Fix for CVE-2013-1416 from:
 http://krbdev.mit.edu/rt/Ticket/Display.html?user=guest&pass=guest&id=7600

--- kdc/do_tgs_req.c.orig	2013-04-17 20:50:13.528009200 +0000
+++ kdc/do_tgs_req.c
@@ -1141,7 +1141,8 @@ prep_reprocess_req(krb5_kdc_req *request
             retval = ENOMEM;
             goto cleanup;
         }
-        strlcpy(comp1_str,comp1->data,comp1->length+1);
+        if (comp1->data != NULL)
+	    memcpy(comp1_str, comp1->data, comp1->length);
 
         if ((krb5_princ_type(kdc_context, request->server) == KRB5_NT_SRV_HST ||
              krb5_princ_type(kdc_context, request->server) == KRB5_NT_SRV_INST ||
@@ -1164,7 +1165,8 @@ prep_reprocess_req(krb5_kdc_req *request
                 retval = ENOMEM;
                 goto cleanup;
             }
-            strlcpy(temp_buf, comp2->data,comp2->length+1);
+            if (comp2->data != NULL)
+		memcpy(temp_buf, comp2->data, comp2->length);
             retval = krb5int_get_domain_realm_mapping(kdc_context, temp_buf, &realms);
             free(temp_buf);
             if (retval) {
