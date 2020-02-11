$NetBSD: patch-src_dns_dns__lookup.c,v 1.6 2020/02/11 20:40:27 triaxx Exp $

Fix runtime problem when mysql PKG_OPTIONS is enabled.

--- src/dns/dns_lookup.c.orig	2019-12-15 16:13:04.000000000 +0000
+++ src/dns/dns_lookup.c
@@ -245,6 +245,8 @@
 
 /* Local stuff. */
 
+struct __res_state rstate;
+
  /*
   * Structure to keep track of things while decoding a name server reply.
   */
@@ -308,7 +310,7 @@ typedef struct DNS_REPLY {
 
 /* dns_res_query - a res_query() clone that can return negative replies */
 
-static int dns_res_query(const char *name, int class, int type,
+static int dns_res_query(res_state statp, const char *name, int class, int type,
 			         unsigned char *answer, int anslen)
 {
     unsigned char msg_buf[MAX_DNS_QUERY_SIZE];
@@ -337,14 +339,14 @@ static int dns_res_query(const char *nam
 #define NO_MKQUERY_DATA_LEN     ((int) 0)
 #define NO_MKQUERY_NEWRR        ((unsigned char *) 0)
 
-    if ((len = res_mkquery(QUERY, name, class, type, NO_MKQUERY_DATA_BUF,
+    if ((len = res_nmkquery(statp, QUERY, name, class, type, NO_MKQUERY_DATA_BUF,
 			   NO_MKQUERY_DATA_LEN, NO_MKQUERY_NEWRR,
 			   msg_buf, sizeof(msg_buf))) < 0) {
 	SET_H_ERRNO(NO_RECOVERY);
 	if (msg_verbose)
 	    msg_info("res_mkquery() failed");
 	return (len);
-    } else if ((len = res_send(msg_buf, len, answer, anslen)) < 0) {
+    } else if ((len = res_nsend(statp, msg_buf, len, answer, anslen)) < 0) {
 	SET_H_ERRNO(TRY_AGAIN);
 	if (msg_verbose)
 	    msg_info("res_send() failed");
@@ -373,7 +375,7 @@ static int dns_res_query(const char *nam
 
 /* dns_res_search - res_search() that can return negative replies */
 
-static int dns_res_search(const char *name, int class, int type,
+static int dns_res_search(res_state statp, const char *name, int class, int type,
 	               unsigned char *answer, int anslen, int keep_notfound)
 {
     int     len;
@@ -396,7 +398,7 @@ static int dns_res_search(const char *na
     if (keep_notfound)
 	/* Prepare for returning a null-padded server reply. */
 	memset(answer, 0, anslen);
-    len = res_search(name, class, type, answer, anslen);
+    len = res_nsearch(statp, name, class, type, answer, anslen);
     /* Begin API creep workaround. */
     if (len < 0 && h_errno == 0) {
 	SET_H_ERRNO(TRY_AGAIN);
@@ -435,7 +437,7 @@ static int dns_query(const char *name, i
     /*
      * Initialize the name service.
      */
-    if ((_res.options & RES_INIT) == 0 && res_init() < 0) {
+    if ((rstate.options & RES_INIT) == 0 && res_ninit(&rstate) < 0) {
 	if (why)
 	    vstring_strcpy(why, "Name service initialization failure");
 	return (DNS_FAIL);
@@ -464,24 +466,24 @@ static int dns_query(const char *name, i
      */
 #define SAVE_FLAGS (USER_FLAGS | XTRA_FLAGS)
 
-    saved_options = (_res.options & SAVE_FLAGS);
+    saved_options = (rstate.options & SAVE_FLAGS);
 
     /*
      * Perform the lookup. Claim that the information cannot be found if and
      * only if the name server told us so.
      */
     for (;;) {
-	_res.options &= ~saved_options;
-	_res.options |= flags;
+	rstate.options &= ~saved_options;
+	rstate.options |= flags;
 	if (keep_notfound && var_dns_ncache_ttl_fix) {
-	    len = dns_res_query((char *) name, C_IN, type, reply->buf,
+		len = dns_res_query(&rstate, (char *) name, C_IN, type, reply->buf,
 				reply->buf_len);
 	} else {
-	    len = dns_res_search((char *) name, C_IN, type, reply->buf,
+		len = dns_res_search(&rstate, (char *) name, C_IN, type, reply->buf,
 				 reply->buf_len, keep_notfound);
 	}
-	_res.options &= ~flags;
-	_res.options |= saved_options;
+	rstate.options &= ~flags;
+	rstate.options |= saved_options;
 	reply_header = (HEADER *) reply->buf;
 	reply->rcode = reply_header->rcode;
 	if (h_errno != 0) {
