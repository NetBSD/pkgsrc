$NetBSD: patch-router_router.c,v 1.1 2011/02/06 19:23:51 schnoebe Exp $

# correct a segfault in the router
# fixed upstream as r920 (will be in 2.2.12)

--- router/router.c.orig	2010-08-08 15:50:56.000000000 +0000
+++ router/router.c
@@ -886,7 +886,7 @@ static int _router_sx_callback(sx_t s, s
             }
 
             /* top element must be router scoped */
-            if(NAD_NURI_L(nad, NAD_ENS(nad, 0)) != strlen(uri_COMPONENT) || strncmp(uri_COMPONENT, NAD_NURI(nad, NAD_ENS(nad, 0)), strlen(uri_COMPONENT)) != 0) {
+            if(NAD_ENS(nad, 0) < 0 || NAD_NURI_L(nad, NAD_ENS(nad, 0)) != strlen(uri_COMPONENT) || strncmp(uri_COMPONENT, NAD_NURI(nad, NAD_ENS(nad, 0)), strlen(uri_COMPONENT)) != 0) {
                 log_debug(ZONE, "invalid packet namespace, dropping");
                 nad_free(nad);
                 return 0;
