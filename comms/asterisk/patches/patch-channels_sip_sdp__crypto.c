$NetBSD: patch-channels_sip_sdp__crypto.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- channels/sip/sdp_crypto.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ channels/sip/sdp_crypto.c
@@ -187,6 +187,7 @@ err:
 
 int sdp_crypto_process(struct sdp_crypto *p, const char *attr, struct ast_rtp_instance *rtp, struct sip_srtp *srtp)
 {
+	char buf[10];
 	char *str = NULL;
 	char *tag = NULL;
 	char *suite = NULL;
@@ -220,8 +221,10 @@ int sdp_crypto_process(struct sdp_crypto
 		return -1;
 	}
 
-	/* RFC4568 9.1 - tag is 1-9 digits, greater than zero */
-	if (sscanf(tag, "%30d", &p->tag) != 1 || p->tag <= 0 || p->tag > 999999999) {
+	/* RFC4568 9.1 - tag is 1-9 digits */
+	p->tag = atoi(tag);
+	snprintf(buf, sizeof(buf), "%d", p->tag);
+	if (strcmp(buf, tag) || p->tag < 0 || p->tag > 999999999) {
 		ast_log(LOG_WARNING, "Unacceptable a=crypto tag: %s\n", tag);
 		return -1;
 	}
