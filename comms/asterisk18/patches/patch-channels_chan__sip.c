$NetBSD: patch-channels_chan__sip.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- channels/chan_sip.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ channels/chan_sip.c
@@ -2411,7 +2411,7 @@ static int sip_is_token(const char *str)
 
 	is_token = 1;
 	do {
-		if (!isalnum(*str)
+		if (!isalnum((unsigned char)*str)
 			&& !strchr("-.!%*_+`'~", *str)) {
 			/* The character is not allowed in a token. */
 			is_token = 0;
@@ -11624,7 +11624,7 @@ static int process_sdp_a_image(const cha
 	 * code reviews).
 	 */
 	for (pos = attrib; *pos; ++pos) {
-		*pos = tolower(*pos);
+		*pos = tolower((unsigned char)*pos);
 	}
 
 	if ((sscanf(attrib, "t38faxmaxbuffer:%30u", &x) == 1)) {
@@ -20014,7 +20014,7 @@ static int manager_show_registry(struct 
 			"DomainPort: %d\r\n"
 			"Refresh: %d\r\n"
 			"State: %s\r\n"
-			"RegistrationTime: %ld\r\n"
+			"RegistrationTime: %jd\r\n"
 			"\r\n",
 			idtext,
 			iterator->hostname,
@@ -20024,7 +20024,7 @@ static int manager_show_registry(struct 
 			iterator->regdomainport ? iterator->regdomainport : STANDARD_SIP_PORT,
 			iterator->refresh,
 			regstate2str(iterator->regstate),
-			(long) iterator->regtime.tv_sec);
+			(intmax_t) iterator->regtime.tv_sec);
 
 		ao2_unlock(iterator);
 		ao2_t_ref(iterator, -1, "manager_show_registry iter");
