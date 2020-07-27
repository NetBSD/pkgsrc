$NetBSD: patch-libopendmarc_opendmarc__spf__dns.c,v 1.1 2020/07/27 20:41:10 oster Exp $

Patch from Roy Marples: if we have res_ndestroy(), use that in place of just res_nclose().

--- libopendmarc/opendmarc_spf_dns.c.orig	2015-02-23 20:31:51.000000000 +0000
+++ libopendmarc/opendmarc_spf_dns.c
@@ -108,7 +108,11 @@ opendmarc_spf_dns_lookup_a_actual(char *
 
 #ifdef HAVE_RES_NINIT
 	k = res_nquery(&resp, bp, C_IN, sought, a_buf, sizeof a_buf);
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #else /* HAVE_RES_NINIT */
 	k = res_query(bp, C_IN, sought, a_buf, sizeof a_buf);
 #endif /* HAVE_RES_NINIT */
@@ -253,7 +257,11 @@ opendmarc_spf_dns_lookup_mx(char *domain
         memset(&resp, '\0', sizeof resp);
 	res_ninit(&resp);
 	k = res_nquery(&resp, domain, C_IN, T_MX, (u_char *) &q, sizeof(q));
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #else /* HAVE_RES_NINIT */
 	k = res_query(domain, C_IN, T_MX, (u_char *) &q, sizeof(q));
 #endif /* HAVE_RES_NINIT */
@@ -366,7 +374,11 @@ opendmarc_spf_dns_lookup_ptr(char *ip, c
         memset(&resp, '\0', sizeof resp);
 	res_ninit(&resp);
 	k = res_nquery(&resp, (char *)buf, C_IN, T_PTR, (u_char *) &q, sizeof(q));
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #else /* HAVE_RES_NINIT */
 	k = res_query((char *)buf, C_IN, T_PTR, (u_char *) &q, sizeof(q));
 #endif /* HAVE_RES_NINIT */
@@ -461,7 +473,11 @@ opendmarc_spf_dns_does_domain_exist(char
         (void) res_nquery(&resp, domain, C_IN, T_AAAA, aaaa_q, sizeof aaaa_q);  
 #endif /* T_AAAA */
         (void) res_nquery(&resp, domain, C_IN, T_MX, mx_q, sizeof mx_q);  
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #else /* HAVE_RES_NINIT */
         (void) res_query(domain, C_IN, T_A, a_q, sizeof a_q);  
 #ifdef T_AAAA
@@ -603,13 +619,21 @@ opendmarc_spf_dns_get_record(char *domai
 		}
 		*rp = h_errno;
 #ifdef HAVE_RES_NINIT 
+#ifdef HAVE_RES_NDESTROY
+		res_ndestroy(&resp);
+#else
 		res_nclose(&resp);
+#endif
 #endif /* HAVE_RES_NINIT */
 		return NULL;
 	}
 got_spf_record:
 #ifdef HAVE_RES_NINIT 
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #endif /* HAVE_RES_NINIT */
 
 	if (k > (int)(sizeof txt_buf))
