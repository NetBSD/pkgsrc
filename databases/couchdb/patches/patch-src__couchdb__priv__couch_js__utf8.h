$NetBSD: patch-src__couchdb__priv__couch_js__utf8.h,v 1.1 2011/12/20 14:08:55 fhajny Exp $

Fix missing newline.
--- src/couchdb/priv/couch_js/utf8.h.orig	2011-10-23 17:38:54.000000000 +0000
+++ src/couchdb/priv/couch_js/utf8.h
@@ -16,4 +16,4 @@
 char* enc_string(JSContext* cx, jsval arg, size_t* buflen);
 JSString* dec_string(JSContext* cx, const char* buf, size_t buflen);
 
-#endif
\ No newline at end of file
+#endif
