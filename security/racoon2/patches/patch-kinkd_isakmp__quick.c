$NetBSD: patch-kinkd_isakmp__quick.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix unused

--- kinkd/isakmp_quick.c.orig	2009-09-04 15:59:33.000000000 -0400
+++ kinkd/isakmp_quick.c	2018-05-28 21:12:13.401432933 -0400
@@ -191,9 +191,11 @@
 	}
 
 	if (iph2->id_p) {
+#if 0
 		uint8_t dummy_plen;
 		uint16_t dummy_ulproto;
 		int ret;
+#endif
 
 		plog(LLV_DEBUG, LOCATION, NULL, "received IDci2:");
 		plogdump(LLV_DEBUG, iph2->id_p->v, iph2->id_p->l);
@@ -212,9 +214,11 @@
 #endif
 	}
 	if (iph2->id) {
+#if 0
 		uint8_t dummy_plen;
 		uint16_t dummy_ulproto;
 		int ret;
+#endif
 
 		plog(LLV_DEBUG, LOCATION, NULL, "received IDcr2:");
 		plogdump(LLV_DEBUG, iph2->id->v, iph2->id->l);
@@ -258,7 +262,9 @@
 {
 	rc_vchar_t *pbuf = NULL;	/* for payload parsing */
 	struct isakmp_parse_t *pa;
+#if 0
 	int f_id;
+#endif
 	int error = ISAKMP_INTERNAL_ERROR;
 
 	/*
@@ -290,7 +296,9 @@
 	 * parse the payloads.
 	 */
 	iph2->sa_ret = NULL;
+#if 0
 	f_id = 0;	/* flag to use checking ID */
+#endif
 	for (; pa->type; pa++) {
 
 		switch (pa->type) {
@@ -319,9 +327,9 @@
 
 		case ISAKMP_NPTYPE_ID:
 		    {
+#if 0	/* ID payloads are not supported yet. */
 			rc_vchar_t *vp;
 
-#if 0	/* ID payloads are not supported yet. */
 			/* check ID value */
 			if (f_id == 0) {
 				/* for IDci */
