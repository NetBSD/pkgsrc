$NetBSD: patch-libopendmarc_opendmarc__dns.c,v 1.1 2020/07/27 20:41:10 oster Exp $

Patch from Roy Marples: if we have res_ndestroy(), use that in place of just res_nclose().

--- libopendmarc/opendmarc_dns.c.orig	2015-02-23 20:31:51.000000000 +0000
+++ libopendmarc/opendmarc_dns.c
@@ -211,7 +211,11 @@ dmarc_dns_get_record(char *domain, int *
 	(void) opendmarc_policy_library_dns_hook(&resp.nscount,
                                                  &resp.nsaddr_list);
 	answer_len = res_nquery(&resp, bp, C_IN, T_TXT, answer_buf, sizeof answer_buf);
+#ifdef HAVE_RES_NDESTROY
+	res_ndestroy(&resp);
+#else
 	res_nclose(&resp);
+#endif
 #else /* HAVE_RES_NINIT */
 #if defined RES_USE_DNSSEC
 	_res.options |= RES_USE_DNSSEC;
