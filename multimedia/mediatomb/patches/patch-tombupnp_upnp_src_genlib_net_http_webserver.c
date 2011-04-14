$NetBSD: patch-tombupnp_upnp_src_genlib_net_http_webserver.c,v 1.1 2011/04/14 07:26:34 adam Exp $

Fix building with Clang.

--- tombupnp/upnp/src/genlib/net/http/webserver.c.orig	2011-04-14 07:19:15.000000000 +0000
+++ tombupnp/upnp/src/genlib/net/http/webserver.c
@@ -310,7 +310,7 @@ search_extension( IN const char *extensi
 *	 0 - On Sucess														
 *	 UPNP_E_OUTOF_MEMORY - on memory allocation failures				
 ************************************************************************/
-XINLINE int
+int
 get_content_type( IN const char *filename,
                   OUT DOMString * content_type )
 {
