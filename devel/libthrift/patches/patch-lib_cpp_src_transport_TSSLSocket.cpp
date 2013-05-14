$NetBSD: patch-lib_cpp_src_transport_TSSLSocket.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/transport/TSSLSocket.cpp.orig	2013-04-30 19:10:02.000000000 +0000
+++ lib/cpp/src/transport/TSSLSocket.cpp
@@ -77,15 +77,15 @@ SSL* SSLContext::createSSL() {
 }
 
 // TSSLSocket implementation
-TSSLSocket::TSSLSocket(shared_ptr<SSLContext> ctx):
+TSSLSocket::TSSLSocket(boost::shared_ptr<SSLContext> ctx):
   TSocket(), server_(false), ssl_(NULL), ctx_(ctx) {
 }
 
-TSSLSocket::TSSLSocket(shared_ptr<SSLContext> ctx, int socket):
+TSSLSocket::TSSLSocket(boost::shared_ptr<SSLContext> ctx, int socket):
   TSocket(socket), server_(false), ssl_(NULL), ctx_(ctx) {
 }
 
-TSSLSocket::TSSLSocket(shared_ptr<SSLContext> ctx, string host, int port):
+TSSLSocket::TSSLSocket(boost::shared_ptr<SSLContext> ctx, string host, int port):
   TSocket(host, port), server_(false), ssl_(NULL), ctx_(ctx) {
 }
 
@@ -350,7 +350,7 @@ TSSLSocketFactory::TSSLSocketFactory(): 
     randomize();
   }
   count_++;
-  ctx_ = shared_ptr<SSLContext>(new SSLContext);
+  ctx_ = boost::shared_ptr<SSLContext>(new SSLContext);
 }
 
 TSSLSocketFactory::~TSSLSocketFactory() {
@@ -361,29 +361,29 @@ TSSLSocketFactory::~TSSLSocketFactory() 
   }
 }
 
-shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket() {
-  shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_));
+boost::shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket() {
+  boost::shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_));
   setup(ssl);
   return ssl;
 }
 
-shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket(int socket) {
-  shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_, socket));
+boost::shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket(int socket) {
+  boost::shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_, socket));
   setup(ssl);
   return ssl;
 }
 
-shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket(const string& host,
+boost::shared_ptr<TSSLSocket> TSSLSocketFactory::createSocket(const string& host,
                                                        int port) {
-  shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_, host, port));
+  boost::shared_ptr<TSSLSocket> ssl(new TSSLSocket(ctx_, host, port));
   setup(ssl);
   return ssl;
 }
 
-void TSSLSocketFactory::setup(shared_ptr<TSSLSocket> ssl) {
+void TSSLSocketFactory::setup(boost::shared_ptr<TSSLSocket> ssl) {
   ssl->server(server());
   if (access_ == NULL && !server()) {
-    access_ = shared_ptr<AccessManager>(new DefaultClientAccessManager);
+    access_ = boost::shared_ptr<AccessManager>(new DefaultClientAccessManager);
   }
   if (access_ != NULL) {
     ssl->access(access_);
