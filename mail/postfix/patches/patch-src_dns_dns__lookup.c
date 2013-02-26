$NetBSD: patch-src_dns_dns__lookup.c,v 1.1 2013/02/26 19:56:18 garbled Exp $

--- src/dns/dns_lookup.c.orig	2013-02-26 19:34:50.000000000 +0000
+++ src/dns/dns_lookup.c
@@ -153,6 +153,8 @@
 
 /* Local stuff. */
 
+struct __res_state rstate;
+
  /*
   * Structure to keep track of things while decoding a name server reply.
   */
@@ -192,7 +194,7 @@ static int dns_query(const char *name, i
     /*
      * Initialize the name service.
      */
-    if ((_res.options & RES_INIT) == 0 && res_init() < 0) {
+    if ((rstate.options & RES_INIT) == 0 && res_ninit(&rstate) < 0) {
 	if (why)
 	    vstring_strcpy(why, "Name service initialization failure");
 	return (DNS_FAIL);
@@ -206,18 +208,18 @@ static int dns_query(const char *name, i
 
     if ((flags & USER_FLAGS) != flags)
 	msg_panic("dns_query: bad flags: %d", flags);
-    saved_options = (_res.options & USER_FLAGS);
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
 	if (len < 0) {
 	    if (why)
 		vstring_sprintf(why, "Host or domain name not found. "
