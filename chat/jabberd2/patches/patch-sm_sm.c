$NetBSD: patch-sm_sm.c,v 1.1 2011/02/06 19:23:51 schnoebe Exp $

# fix segfault when debugging is turned on/up.  
# fixed up stream as part of r910 (will be released with 2.2.12)

--- sm/sm.c.orig	2010-08-08 15:50:55.000000000 +0000
+++ sm/sm.c
@@ -138,7 +138,7 @@ int sm_sx_callback(sx_t s, sx_event_t e,
                 elem = nad_append_elem(nad, ns, "bind", 0);
                 nad_set_attr(nad, elem, -1, "name", domain, len);
                 nad_append_attr(nad, -1, "multi", "to");
-                log_debug(ZONE, "requesting domain bind for '%.*s'", domain, len);
+                log_debug(ZONE, "requesting domain bind for '%.*s'", len, domain);
                 sx_nad_write(sm->router, nad);
             
             } while(xhash_iter_next(sm->hosts));
