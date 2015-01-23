$NetBSD: patch-src_pop3-login_client.c,v 1.1 2015/01/23 12:17:47 wiz Exp $

Fix for CVE-2014-3430.
Based on http://hg.dovecot.org/dovecot-1.2/raw-rev/8ba4253adc9b

--- src/pop3-login/client.c.orig	2010-01-24 23:14:17.000000000 +0000
+++ src/pop3-login/client.c
@@ -359,6 +359,8 @@ void client_destroy(struct pop3_client *
 
 	client_unlink(&client->common);
 
+	if (!client->login_success && client->common.proxy != NULL)
+		ssl_proxy_destroy(client->common.proxy);
 	if (client->common.input != NULL)
 		i_stream_close(client->common.input);
 	if (client->output != NULL)
