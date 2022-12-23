$NetBSD: patch-src_libs_zbxsysinfo_simple_simple.c,v 1.1 2022/12/23 09:25:17 wiz Exp $

Fix build with curl 7.87.0.

--- src/libs/zbxsysinfo/simple/simple.c.orig	2021-10-18 08:01:42.000000000 +0000
+++ src/libs/zbxsysinfo/simple/simple.c
@@ -164,25 +164,25 @@ static int	check_https(const char *host,
 	else
 		zbx_snprintf(https_host, sizeof(https_host), "%s%s", (0 == strncmp(host, "https://", 8) ? "" : "https://"), host);
 
-	if (CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_USERAGENT, "Zabbix " ZABBIX_VERSION)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_URL, https_host)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_PORT, (long)port)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_NOBODY, 1L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_SSL_VERIFYPEER, 0L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_SSL_VERIFYHOST, 0L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_TIMEOUT, (long)timeout)))
+	if (CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_USERAGENT, "Zabbix " ZABBIX_VERSION)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_URL, https_host)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_PORT, (long)port)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_NOBODY, 1L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYPEER, 0L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYHOST, 0L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_TIMEOUT, (long)timeout)))
 	{
-		zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set cURL option [%d]: %s",
-				__func__, (int)opt, curl_easy_strerror(err));
+		zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set cURL option: %s",
+				__func__, curl_easy_strerror(err));
 		goto clean;
 	}
 
 	if (NULL != CONFIG_SOURCE_IP)
 	{
-		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_INTERFACE, CONFIG_SOURCE_IP)))
+		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, CURLOPT_INTERFACE, CONFIG_SOURCE_IP)))
 		{
-			zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set source interface option [%d]: %s",
-					__func__, (int)opt, curl_easy_strerror(err));
+			zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set source interface option: %s",
+					__func__, curl_easy_strerror(err));
 			goto clean;
 		}
 	}
