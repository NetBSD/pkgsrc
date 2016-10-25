$NetBSD: patch-channels_chan__sip.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- channels/chan_sip.c.orig    2015-10-09 21:48:48.000000000 +0000
+++ channels/chan_sip.c
@@ -19329,7 +19333,7 @@ static int manager_show_registry(struct 
 			"DomainPort: %d\r\n"
 			"Refresh: %d\r\n"
 			"State: %s\r\n"
-			"RegistrationTime: %ld\r\n"
+			"RegistrationTime: %jd\r\n"
 			"\r\n",
 			idtext,
 			iterator->hostname,
@@ -19339,7 +19343,7 @@ static int manager_show_registry(struct 
 			iterator->regdomainport ? iterator->regdomainport : STANDARD_SIP_PORT,
 			iterator->refresh,
 			regstate2str(iterator->regstate),
-			(long) iterator->regtime.tv_sec);
+			(intmax_t) iterator->regtime.tv_sec);
 
 		ao2_unlock(iterator);
 		ao2_t_ref(iterator, -1, "manager_show_registry iter");
