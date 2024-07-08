$NetBSD: patch-channels_chan__sip.c,v 1.2 2024/07/08 05:03:01 jnemeth Exp $

--- channels/chan_sip.c.orig	2023-07-07 19:07:43.000000000 +0000
+++ channels/chan_sip.c
@@ -176,7 +176,6 @@
 /*** MODULEINFO
 	<use type="module">res_crypto</use>
 	<use type="module">res_http_websocket</use>
-	<defaultenabled>no</defaultenabled>
 	<support_level>deprecated</support_level>
 	<replacement>chan_pjsip</replacement>
 	<deprecated_in>17</deprecated_in>
@@ -2464,7 +2463,7 @@ static int sip_is_token(const char *str)
 
 	is_token = 1;
 	do {
-		if (!isalnum(*str)
+		if (!isalnum((unsigned char)*str)
 			&& !strchr("-.!%*_+`'~", *str)) {
 			/* The character is not allowed in a token. */
 			is_token = 0;
@@ -11768,7 +11767,7 @@ static int process_sdp_a_image(const cha
 	 * code reviews).
 	 */
 	for (pos = attrib; *pos; ++pos) {
-		*pos = tolower(*pos);
+		*pos = tolower((unsigned char)*pos);
 	}
 
 	if ((sscanf(attrib, "t38faxmaxbuffer:%30u", &x) == 1)) {
@@ -20216,7 +20215,7 @@ static int manager_show_registry(struct 
 			"DomainPort: %d\r\n"
 			"Refresh: %d\r\n"
 			"State: %s\r\n"
-			"RegistrationTime: %ld\r\n"
+			"RegistrationTime: %jd\r\n"
 			"\r\n",
 			idtext,
 			iterator->hostname,
@@ -20226,7 +20225,7 @@ static int manager_show_registry(struct 
 			iterator->regdomainport ? iterator->regdomainport : STANDARD_SIP_PORT,
 			iterator->refresh,
 			regstate2str(iterator->regstate),
-			(long) iterator->regtime.tv_sec);
+			(intmax_t) iterator->regtime.tv_sec);
 
 		ao2_unlock(iterator);
 		ao2_t_ref(iterator, -1, "manager_show_registry iter");
