$NetBSD: patch-s2s_out.c,v 1.1 2011/02/06 19:23:51 schnoebe Exp $

# Resolver doesn't return IPv4 Address if resolve_aaaa (IPv6) is enabled
# fixed upstream as part of r915 (will be available in 2.2.12)

--- s2s/out.c	(revision 914)
+++ s2s/out.c	(revision 915)
@@ -1071,10 +1071,8 @@
 
         /* resolve hostname */
         free(query->cur_host);
-        query->cur_host = strndup(ipport, ipport_len);
-        tmp = malloc(sizeof(char) * port_len + 1);
-        strncpy(tmp, c, port_len);
-        tmp[port_len] = '\0';
+        query->cur_host = strndup(ipport, ip_len);
+        tmp = strndup(c, port_len);
         query->cur_port = atoi(tmp);
         free(tmp);
         query->cur_prio = res->prio;
@@ -1082,29 +1080,23 @@
         query->cur_expiry = res->expiry;
         log_debug(ZONE, "dns ttl for %s@%p limited to %d", query->name, query, query->cur_expiry);
 
-        tmp = malloc(sizeof(char) * ip_len + 1);
-        strncpy(tmp, ipport, ip_len);
-        tmp[ip_len] = '\0';
-
         if (query->s2s->resolve_aaaa) {
-            log_debug(ZONE, "dns request for %s@%p: AAAA %s", query->name, query, tmp);
+            log_debug(ZONE, "dns request for %s@%p: AAAA %s", query->name, query, query->cur_host);
 
-            query->query = dns_submit_a6(NULL, tmp, DNS_NOSRCH, _dns_result_aaaa, query);
+            query->query = dns_submit_a6(NULL, query->cur_host, DNS_NOSRCH, _dns_result_aaaa, query);
 
             /* if submit failed, call ourselves with a NULL result */
             if (query->query == NULL)
                 _dns_result_aaaa(ctx, NULL, query);
         } else {
-            log_debug(ZONE, "dns request for %s@%p: A %s", query->name, query, tmp);
+            log_debug(ZONE, "dns request for %s@%p: A %s", query->name, query, query->cur_host);
 
-            query->query = dns_submit_a4(NULL, tmp, DNS_NOSRCH, _dns_result_a, query);
+            query->query = dns_submit_a4(NULL, query->cur_host, DNS_NOSRCH, _dns_result_a, query);
 
             /* if submit failed, call ourselves with a NULL result */
             if (query->query == NULL)
                 _dns_result_a(ctx, NULL, query);
         }
-        
-        free(tmp);
 
     /* finished */
     } else {
