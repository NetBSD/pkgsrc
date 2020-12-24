--- libopendmarc/opendmarc_spf_dns.c.orig	2020-09-22 03:01:49.272695446 +0200
+++ libopendmarc/opendmarc_spf_dns.c	2020-09-22 03:05:01.660275230 +0200
@@ -107,9 +107,13 @@
 		++bp;
 
 #ifdef HAVE_RES_NINIT
 	k = res_nquery(&resp, bp, C_IN, sought, a_buf, sizeof a_buf);
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #else /* HAVE_RES_NINIT */
 	k = res_query(bp, C_IN, sought, a_buf, sizeof a_buf);
 #endif /* HAVE_RES_NINIT */
 	if (k < 0)
@@ -252,9 +256,13 @@
 #ifdef HAVE_RES_NINIT 
         memset(&resp, '\0', sizeof resp);
 	res_ninit(&resp);
 	k = res_nquery(&resp, domain, C_IN, T_MX, (u_char *) &q, sizeof(q));
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #else /* HAVE_RES_NINIT */
 	k = res_query(domain, C_IN, T_MX, (u_char *) &q, sizeof(q));
 #endif /* HAVE_RES_NINIT */
 
@@ -365,9 +373,13 @@
 #ifdef HAVE_RES_NINIT 
         memset(&resp, '\0', sizeof resp);
 	res_ninit(&resp);
 	k = res_nquery(&resp, (char *)buf, C_IN, T_PTR, (u_char *) &q, sizeof(q));
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #else /* HAVE_RES_NINIT */
 	k = res_query((char *)buf, C_IN, T_PTR, (u_char *) &q, sizeof(q));
 #endif /* HAVE_RES_NINIT */
 
@@ -460,9 +472,13 @@
 #ifdef T_AAAA
         (void) res_nquery(&resp, domain, C_IN, T_AAAA, aaaa_q, sizeof aaaa_q);  
 #endif /* T_AAAA */
         (void) res_nquery(&resp, domain, C_IN, T_MX, mx_q, sizeof mx_q);  
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #else /* HAVE_RES_NINIT */
         (void) res_query(domain, C_IN, T_A, a_q, sizeof a_q);  
 #ifdef T_AAAA
         (void) res_query(domain, C_IN, T_AAAA, aaaa_q, sizeof aaaa_q);  
@@ -602,15 +618,23 @@
 				goto got_spf_record;
 		}
 		*rp = h_errno;
 #ifdef HAVE_RES_NINIT 
+#ifdef HAVE_RES_NDESTROY
+		res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 		res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #endif /* HAVE_RES_NINIT */
 		return NULL;
 	}
 got_spf_record:
 #ifdef HAVE_RES_NINIT 
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #endif /* HAVE_RES_NINIT */
 
 	if (k > (int)(sizeof txt_buf))
 		k = sizeof txt_buf;
