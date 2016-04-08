$NetBSD: patch-third-party_mongoose_mongoose.c,v 1.1 2016/04/08 16:59:07 adam Exp $

Updated to the latest version from github.com/ntop/ntopng.
On NetBSD, this fixes a problem with HTTP listening on IPv6 only.

--- third-party/mongoose/mongoose.c.orig	2015-11-30 19:15:18.000000000 +0100
+++ third-party/mongoose/mongoose.c	2016-04-06 15:53:31.000000000 +0200
@@ -444,6 +444,8 @@
   struct sockaddr_in sin;
 #if defined(USE_IPV6)
   struct sockaddr_in6 sin6;
+#else
+  struct sockaddr sin6;
 #endif
 };
 
@@ -4398,37 +4400,45 @@
 // Examples: 80, 443s, 127.0.0.1:3128, 1.2.3.4:8080s
 // TODO(lsm): add parsing of the IPv6 address
 static int parse_port_string(const struct vec *vec, struct socket *so) {
-  int a, b, c, d, port, len;
-
+  union usa *sa = (union usa *)&so->lsa;
+  int a, b, c, d, port = 0, len = 0;
+#if defined(USE_IPV6)
+  char buf[100];
+#endif
   // MacOS needs that. If we do not zero it, subsequent bind() will fail.
   // Also, all-zeroes in the socket address means binding to all addresses
   // for both IPv4 and IPv6 (INADDR_ANY and IN6ADDR_ANY_INIT).
-  memset(so, 0, sizeof(*so));
+  memset(sa, 0, sizeof(*sa));
 
-  if (sscanf(vec->ptr, "%d.%d.%d.%d:%d%n", &a, &b, &c, &d, &port, &len) == 5) {
-    // Bind to a specific IPv4 address
-    so->lsa.sin.sin_addr.s_addr = htonl((a << 24) | (b << 16) | (c << 8) | d);
-  } else if (sscanf(vec->ptr, "%d%n", &port, &len) != 1 ||
-             len <= 0 ||
-             len > (int) vec->len ||
-             (vec->ptr[len] && vec->ptr[len] != 's' &&
-              vec->ptr[len] != 'r' && vec->ptr[len] != ',')) {
-    return 0;
-  }
+  sa->sin.sin_family = AF_INET;
+
+  if (sscanf(vec->ptr, "%u.%u.%u.%u:%u%n", &a, &b, &c, &d, &port, &len) == 5) {
+    /* Bind to a specific IPv4 address, e.g. 127.0.0.1:8080 */
+    sa->sin.sin_addr.s_addr =
+      htonl(((uint32_t) a << 24) | ((uint32_t) b << 16) | c << 8 | d);
+    sa->sin.sin_port = htons((uint16_t) port);
 
-  so->is_ssl = vec->ptr[len] == 's';
-  so->ssl_redir = vec->ptr[len] == 'r';
 #if defined(USE_IPV6)
-  if(is_ip6_enabled) {
-    so->lsa.sin6.sin6_family = AF_INET6;
-    so->lsa.sin6.sin6_port = htons((uint16_t) port);
-  } else { /* NTOP - fall back to IPv4 */
-    so->lsa.sin.sin_family = AF_INET;
-    so->lsa.sin.sin_port = htons((uint16_t) port);
+  } else if (sscanf(vec->ptr, "[%[^]]]:%u%n", buf, &port, &len) == 2 &&
+	     inet_pton(AF_INET6, buf, &sa->sin6.sin6_addr)) {
+    /* IPv6 address, e.g. [3ffe:2a00:100:7031::1]:8080 */
+    sa->sin6.sin6_family = AF_INET6;
+    sa->sin.sin_port = htons((uint16_t) port);
+#endif
+
+  } else if (sscanf(vec->ptr, ":%u%n", &port, &len) == 1 ||
+	     sscanf(vec->ptr, "%u%n", &port, &len) == 1) {
+    /* If only port is specified, bind to IPv4, INADDR_ANY */
+    sa->sin.sin_port = htons((uint16_t) port);
+  } else {
+    return -1;
   }
-#else
-  so->lsa.sin.sin_family = AF_INET;
-  so->lsa.sin.sin_port = htons((uint16_t) port);
+
+  so->is_ssl = (vec->ptr[len] && vec->ptr[len] == 's');
+  so->ssl_redir = (vec->ptr[len] && vec->ptr[len] == 'r');
+
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+  so->lsa.sin.sin_len = sizeof(struct sockaddr_in);
 #endif
 
   return 1;
@@ -4439,6 +4449,15 @@
   int on = 1, success = 1;
   struct vec vec;
   struct socket so;
+  int rc_setsockopt = 0, rc_bind = 0, rc_listen = 0;
+  union usa *sa = (union usa *)&so.lsa;
+
+  /*
+    #if defined(USE_IPV6)
+    if(is_ip6_enabled)
+    sa = (const struct sockaddr *)&so.lsa.sin6, sa_len = sizeof(so.lsa.sin6);
+    #endif
+  */
 
   while (success && (list = next_option(list, &vec, NULL)) != NULL) {
     if (!parse_port_string(&vec, &so)) {
@@ -4448,19 +4467,22 @@
     } else if (so.is_ssl && ctx->ssl_ctx == NULL) {
       cry(fc(ctx), "Cannot add SSL socket, is -ssl_certificate option set?");
       success = 0;
-    } else if ((so.sock = socket(so.lsa.sa.sa_family, SOCK_STREAM, 6)) ==
+    } else if ((so.sock = socket(so.lsa.sa.sa_family, SOCK_STREAM, IPPROTO_TCP)) ==
                INVALID_SOCKET ||
                // On Windows, SO_REUSEADDR is recommended only for
                // broadcast UDP sockets
-               setsockopt(so.sock, SOL_SOCKET, SO_REUSEADDR,
+	       (rc_setsockopt = setsockopt(so.sock, SOL_SOCKET, SO_REUSEADDR,
 #ifdef WIN32
 			  (const char*)
 #else
                           (void *) 
 #endif					  
-			  &on, sizeof(on)) != 0 ||
-               bind(so.sock, &so.lsa.sa, sizeof(so.lsa)) != 0 ||
-               listen(so.sock, SOMAXCONN) != 0) {
+					   &on, sizeof(on))) != 0 ||
+	       (rc_bind = bind(so.sock,
+			       &sa->sa,
+			       (sa->sa.sa_family == AF_INET) ? sizeof(sa->sin) : sizeof(sa->sin6))
+		) != 0 ||
+	       (rc_listen = listen(so.sock, SOMAXCONN)) != 0) {
       cry(fc(ctx), "%s: cannot bind to %.*s: %s", __func__,
           (int) vec.len, vec.ptr, strerror(ERRNO));
       closesocket(so.sock);
@@ -5239,6 +5261,10 @@
   check_ipv6_enabled();
 #endif
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+  is_ip6_enabled = 0;
+#endif
+
 #if defined(_WIN32) && !defined(__SYMBIAN32__)
   WSADATA data;
   WSAStartup(MAKEWORD(2,2), &data);
