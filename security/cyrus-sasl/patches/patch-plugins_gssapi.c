$NetBSD: patch-plugins_gssapi.c,v 1.1 2012/01/02 03:25:57 obache Exp $

* Fixes a segfault in gssapi.c
  http://git.cyrusimap.org/cyrus-sasl/commit/?id=fa289f15ceb2b9c64bdcf057a75469808454190d

--- plugins/gssapi.c.orig	2011-05-11 19:25:55.000000000 +0000
+++ plugins/gssapi.c
@@ -370,7 +370,7 @@ sasl_gss_encode(void *context, const str
     }
     
     if (output_token->value && output) {
-	unsigned char * p = (unsigned char *) text->encode_buf;
+	unsigned char * p;
 	
 	ret = _plug_buf_alloc(text->utils,
 			      &(text->encode_buf),
@@ -383,6 +383,8 @@ sasl_gss_encode(void *context, const str
 	    GSS_UNLOCK_MUTEX(text->utils);
 	    return ret;
 	}
+
+	p = (unsigned char *) text->encode_buf;
 	
 	p[0] = (output_token->length>>24) & 0xFF;
 	p[1] = (output_token->length>>16) & 0xFF;
