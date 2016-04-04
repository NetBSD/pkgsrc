$NetBSD: patch-security_manager_ssl_src_nsNSSCallbacks.h,v 1.1 2016/04/04 17:36:35 joerg Exp $

--- security/manager/ssl/src/nsNSSCallbacks.h.orig	2016-04-04 15:21:30.039415148 +0000
+++ security/manager/ssl/src/nsNSSCallbacks.h
@@ -93,7 +93,6 @@ public:
                              const char *http_protocol_variant,
                              const char *path_and_query_string,
                              const char *http_request_method, 
-                             const char *isolation_key,
                              const PRIntervalTime timeout, 
                              SEC_HTTP_REQUEST_SESSION *pRequest);
 
@@ -171,13 +170,11 @@ public:
                              const char *http_protocol_variant,
                              const char *path_and_query_string,
                              const char *http_request_method, 
-                             const char *isolation_key,
                              const PRIntervalTime timeout, 
                              SEC_HTTP_REQUEST_SESSION *pRequest)
   {
     return nsNSSHttpRequestSession::createFcn(session, http_protocol_variant,
                                      path_and_query_string, http_request_method, 
-                                     isolation_key,
                                      timeout, pRequest);
   }
 
