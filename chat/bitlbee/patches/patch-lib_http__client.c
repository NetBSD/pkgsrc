$NetBSD: patch-lib_http__client.c,v 1.1 2011/11/18 21:06:19 tonio Exp $

Fix for MSN login troubles

--- lib/http_client.c	(revision devel,783)
+++ lib/http_client.c	(revision devel,825)
@@ -314,5 +314,5 @@
 	}
 	
-	if( ( req->status_code == 301 || req->status_code == 302 ) && req->redir_ttl-- > 0 )
+	if( ( req->status_code >= 301 && req->status_code <= 303 ) && req->redir_ttl-- > 0 )
 	{
 		char *loc, *new_request, *new_host;
@@ -354,4 +354,5 @@
 			url_t *url;
 			char *s;
+			const char *new_method;
 			
 			s = strstr( loc, "\r\n" );
@@ -369,25 +370,34 @@
 			}
 			
-			/* Okay, this isn't fun! We have to rebuild the request... :-( */
-			new_request = g_malloc( req->request_length + strlen( url->file ) );
-			
-			/* So, now I just allocated enough memory, so I'm
-			   going to use strcat(), whether you like it or not. :-) */
-			
-			sprintf( new_request, "GET %s HTTP/1.0", url->file );
-			
-			s = strstr( req->request, "\r\n" );
-			if( s == NULL )
+			/* Find all headers and, if necessary, the POST request contents.
+			   Skip the old Host: header though. This crappy code here means
+			   anything using this http_client MUST put the Host: header at
+			   the top. */
+			if( !( ( s = strstr( req->request, "\r\nHost: " ) ) &&
+			       ( s = strstr( s + strlen( "\r\nHost: " ), "\r\n" ) ) ) )
 			{
 				req->status_string = g_strdup( "Error while rebuilding request string" );
-				g_free( new_request );
 				g_free( url );
 				goto cleanup;
 			}
 			
-			strcat( new_request, s );
+			/* More or less HTTP/1.0 compliant, from my reading of RFC 2616.
+			   Always perform a GET request unless we received a 301. 303 was
+			   meant for this but it's HTTP/1.1-only and we're specifically
+			   speaking HTTP/1.0. */
+			new_method = req->status_code != 301 || req->request[0] == 'G' ? "GET" : "POST";
+			
+			/* Okay, this isn't fun! We have to rebuild the request... :-( */
+			new_request = g_strdup_printf( "%s %s HTTP/1.0\r\nHost: %s%s",
+			                               new_method, url->file, url->host, s );
+			
 			new_host = g_strdup( url->host );
 			new_port = url->port;
 			new_proto = url->proto;
+			
+			/* If we went from POST to GET, truncate the request content. */
+			if( new_request[0] != req->request[0] && new_request[0] == 'G' &&
+			    ( s = strstr( new_request, "\r\n\r\n" ) ) )
+				s[4] = '\0';
 			
 			g_free( url );
