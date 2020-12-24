$NetBSD: patch-libopendmarc_opendmarc__dns.c,v 1.2 2020/12/24 01:10:23 manu Exp $

Make sure res_init works on zeroed structure
Search for res_ndestroy and use it instead of res_nclose if available

--- libopendmarc/opendmarc_dns.c.orig	2018-11-15 01:58:31.000000000 +0100
+++ libopendmarc/opendmarc_dns.c	2020-12-23 15:57:30.488718786 +0100
@@ -201,16 +201,21 @@
 	while (*bp == '.')
 		++bp;
 
 #ifdef HAVE_RES_NINIT   
+	memset(&resp, 0, sizeof(resp));
 	res_ninit(&resp);
 #ifdef RES_USE_DNSSEC
 	resp.options |= RES_USE_DNSSEC;
 #endif
 	(void) opendmarc_policy_library_dns_hook(&resp.nscount,
                                                  &resp.nsaddr_list);
 	answer_len = res_nquery(&resp, bp, C_IN, T_TXT, answer_buf, sizeof answer_buf);
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else /* HAVE_RES_NDESTROY */
 	res_nclose(&resp);
+#endif /* HAVE_RES_NDESTROY */
 #else /* HAVE_RES_NINIT */
 	res_init();
 #ifdef RES_USE_DNSSEC
 	_res.options |= RES_USE_DNSSEC;
