$NetBSD: patch-src_dns_dns__lookup.c,v 1.3 2014/02/09 05:34:13 taca Exp $

Fix runtime problem when mysql PKG_OPTIONS is enabled.

--- src/dns/dns_lookup.c.orig	2014-01-09 15:00:36.000000000 +0000
+++ src/dns/dns_lookup.c
@@ -194,6 +194,8 @@
 
 /* Local stuff. */
 
+struct __res_state rstate;
+
  /*
   * Structure to keep track of things while decoding a name server reply.
   */
@@ -235,7 +237,7 @@ static int dns_query(const char *name, i
     /*
      * Initialize the name service.
      */
-    if ((_res.options & RES_INIT) == 0 && res_init() < 0) {
+    if ((rstate.options & RES_INIT) == 0 && res_ninit(&rstate) < 0) {
 	if (why)
 	    vstring_strcpy(why, "Name service initialization failure");
 	return (DNS_FAIL);
@@ -264,18 +266,18 @@ static int dns_query(const char *name, i
      */
 #define SAVE_FLAGS (USER_FLAGS | XTRA_FLAGS)
 
-    saved_options = (_res.options & SAVE_FLAGS);
+    saved_options = (rstate.options & USER_FLAGS);
 
     /*
      * Perform the lookup. Claim that the information cannot be found if and
      * only if the name server told us so.
      */
     for (;;) {
-	_res.options &= ~saved_options;
-	_res.options |= flags;
-	len = res_search((char *) name, C_IN, type, reply->buf, reply->buf_len);
-	_res.options &= ~flags;
-	_res.options |= saved_options;
+	rstate.options &= ~saved_options;
+	rstate.options |= flags;
+	len = res_nsearch(&rstate, (char *) name, C_IN, type, reply->buf, reply->buf_len);
+	rstate.options &= ~flags;
+	rstate.options |= saved_options;
 	reply_header = (HEADER *) reply->buf;
 	reply->rcode = reply_header->rcode;
 	if (len < 0) {
