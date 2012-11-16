$NetBSD: patch-jabberd_base_base__accept.c,v 1.1 2012/11/16 00:34:35 joerg Exp $

--- jabberd/base/base_accept.c.orig	2012-11-15 15:40:49.000000000 +0000
+++ jabberd/base/base_accept.c
@@ -64,7 +64,7 @@ typedef struct accept_instance_st
     char *secret;
     int port;
     int timeout;
-    int restrict;
+    int restricted;
     xdbcache offline;
     jid offjid;
     queue q;
@@ -157,7 +157,7 @@ void base_accept_process_xml(mio m, int 
                 */
 
                 /* if we are supposed to be careful about what comes from this socket */
-                if(ai->restrict)
+                if(ai->restricted)
                 {
                     jp = jpacket_new(x);
                     if(jp->type == JPACKET_UNKNOWN || jp->to == NULL || jp->from == NULL || deliver_hostcheck(jp->from->server) != ai->i)
@@ -358,7 +358,7 @@ result base_accept_config(instance id, x
     inst->port        = port;
     inst->timeout     = j_atoi(xmlnode_get_tag_data(x, "timeout"),10);
     if(xmlnode_get_tag(x,"restrict") != NULL)
-        inst->restrict = 1;
+        inst->restricted = 1;
     if(xmlnode_get_tag(x,"offline") != NULL)
     {
         inst->offline = xdb_cache(id);
