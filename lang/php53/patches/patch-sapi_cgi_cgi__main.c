$NetBSD$

Additional fix for CVE-2012-1823.

--- sapi/cgi/cgi_main.c.orig	2012-05-03 13:54:59.000000000 +0000
+++ sapi/cgi/cgi_main.c
@@ -1557,13 +1557,14 @@ int main(int argc, char *argv[])
 			getenv("REQUEST_METHOD")
 		) {
 			cgi = 1;
+			skip_getopt = 1;
 		}
 	}
 
 	if(query_string = getenv("QUERY_STRING")) {
 		decoded_query_string = strdup(query_string);
 		php_url_decode(decoded_query_string, strlen(decoded_query_string));
-		if(*decoded_query_string == '-' && strchr(decoded_query_string, '=') == NULL) {
+		if(*decoded_query_string == '-' && strchr(query_string, '=') == NULL) {
 			skip_getopt = 1;
 		}
 		free(decoded_query_string);
