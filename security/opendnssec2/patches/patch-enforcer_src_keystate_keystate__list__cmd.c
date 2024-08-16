$NetBSD: patch-enforcer_src_keystate_keystate__list__cmd.c,v 1.1 2024/08/16 15:29:36 he Exp $

Guard against key_data_get_zone() returning NULL (which it can do, for
multiple reaons), and avoid keeling over in that case.

Should avoid crashes when a key such as this is present:

(null)                          KSK      unknown   now                      2048  13         43ff9e6e2c011cd6165f25aa7ac6db83 SoftHSM     45696

and you want to list all the keys for a given zone.

Also improve readability of the code by splitting the overly long
condition over multiple lines & indenting.

--- enforcer/src/keystate/keystate_list_cmd.c.orig	2024-08-16 14:50:50.834836266 +0000
+++ enforcer/src/keystate/keystate_list_cmd.c
@@ -199,7 +199,11 @@ perform_keystate_list(int sockfd, db_con
         hsmkey = key_data_get_hsm_key(key);
         key_data_cache_key_states(key);
         tchange = map_keytime(zone, key); /* allocs */
-        if ((printkey != NULL) && (!zonename || !strcmp(zone_db_name(zone), zonename)) && (!keytype || !strcasecmp(keytype,key_data_role_text(key))) && (!keystate || !strcasecmp(keystate, map_keystate(key))))
+        if ((printkey != NULL) && 
+	    (!zonename || (zone && !strcmp(zone_db_name(zone), zonename))) && 
+	    (!keytype || !strcasecmp(keytype,key_data_role_text(key))) && 
+	    (!keystate || !strcasecmp(keystate, map_keystate(key)))
+	   )
             (*printkey)(sockfd, zone, key, tchange, hsmkey);
         free(tchange);
         hsm_key_free(hsmkey);
