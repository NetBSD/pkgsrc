$NetBSD: patch-upnp-src-genlib-net-http-webserver.c,v 1.1 2011/08/20 15:36:16 joerg Exp $

--- upnp/src/genlib/net/http/webserver.c.orig	2011-08-19 14:13:11.000000000 +0000
+++ upnp/src/genlib/net/http/webserver.c
@@ -289,7 +289,7 @@ search_extension( IN const char *extensi
  *	 0 - On Sucess
  *	 UPNP_E_OUTOF_MEMORY - on memory allocation failures
  ************************************************************************/
-UPNP_INLINE int
+static UPNP_INLINE int
 get_content_type( IN const char *filename,
                   OUT DOMString * content_type )
 {
