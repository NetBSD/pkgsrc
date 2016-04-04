$NetBSD: patch-security_manager_ssl_src_nsNSSCallbacks.cpp,v 1.1 2016/04/04 17:36:35 joerg Exp $

--- security/manager/ssl/src/nsNSSCallbacks.cpp.orig	2016-04-04 15:21:08.677783866 +0000
+++ security/manager/ssl/src/nsNSSCallbacks.cpp
@@ -106,18 +106,6 @@ nsHTTPDownloadEvent::Run()
 
   chan->SetLoadFlags(nsIRequest::LOAD_ANONYMOUS);
 
-  // If we have an isolation key, use it as the  URI for this channel.
-  if (!mRequestSession->mIsolationKey.IsEmpty()) {
-    nsCOMPtr<nsIHttpChannelInternal> channelInternal(do_QueryInterface(chan));
-    if (channelInternal) {
-      nsCString documentURISpec("https://");
-      documentURISpec.Append(mRequestSession->mIsolationKey);
-      nsCOMPtr<nsIURI> documentURI;
-      /* nsresult rv = */ NS_NewURI(getter_AddRefs(documentURI), documentURISpec);
-      channelInternal->SetDocumentURI(documentURI);
-    }
-  }
-
   // Create a loadgroup for this new channel.  This way if the channel
   // is redirected, we'll have a way to cancel the resulting channel.
   nsCOMPtr<nsILoadGroup> lg = do_CreateInstance(NS_LOADGROUP_CONTRACTID);
@@ -218,7 +206,6 @@ SECStatus nsNSSHttpRequestSession::creat
                                              const char *http_protocol_variant,
                                              const char *path_and_query_string,
                                              const char *http_request_method, 
-                                             const char *isolationKey,
                                              const PRIntervalTime timeout, 
                                              SEC_HTTP_REQUEST_SESSION *pRequest)
 {
@@ -250,8 +237,6 @@ SECStatus nsNSSHttpRequestSession::creat
   rs->mURL.AppendInt(hss->mPort);
   rs->mURL.Append(path_and_query_string);
 
-  rs->mIsolationKey.Assign(isolationKey);
-
   rs->mRequestMethod = http_request_method;
 
   *pRequest = (void*)rs;
