$NetBSD: patch-channels_chan__sip.c,v 1.1 2025/04/15 15:35:01 manu Exp $

Enable chan_sip build, LP64 fix

--- channels/chan_sip.c.orig	2025-04-15 01:05:54.475841749 +0200
+++ channels/chan_sip.c	2025-04-15 01:06:13.837413309 +0200
@@ -175,9 +175,9 @@
 
 /*** MODULEINFO
 	<use type="module">res_crypto</use>
 	<use type="module">res_http_websocket</use>
-	<defaultenabled>no</defaultenabled>
+	<defaultenabled>yes</defaultenabled>
 	<support_level>deprecated</support_level>
 	<replacement>chan_pjsip</replacement>
 	<deprecated_in>17</deprecated_in>
 	<removed_in>21</removed_in>
@@ -20391,9 +20391,9 @@
 			"Domain: %s\r\n"
 			"DomainPort: %d\r\n"
 			"Refresh: %d\r\n"
 			"State: %s\r\n"
-			"RegistrationTime: %ld\r\n"
+			"RegistrationTime: %jd\r\n"
 			"\r\n",
 			idtext,
 			iterator->hostname,
 			iterator->portno ? iterator->portno : STANDARD_SIP_PORT,
@@ -20401,9 +20401,9 @@
 			S_OR(iterator->regdomain,iterator->hostname),
 			iterator->regdomainport ? iterator->regdomainport : STANDARD_SIP_PORT,
 			iterator->refresh,
 			regstate2str(iterator->regstate),
-			(long) iterator->regtime.tv_sec);
+			(intmax_t) iterator->regtime.tv_sec);
 
 		ao2_unlock(iterator);
 		ao2_t_ref(iterator, -1, "manager_show_registry iter");
 		total++;
