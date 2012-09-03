$NetBSD: patch-plugins_webinterface_httpresponseheader.h,v 1.1 2012/09/03 10:14:44 marino Exp $

Fix "anachronistic old style base class initializer" error

--- plugins/webinterface/httpresponseheader.h.orig	2012-06-12 10:09:58.000000000 +0000
+++ plugins/webinterface/httpresponseheader.h
@@ -38,7 +38,7 @@ namespace kt
 		int minor;
 		
 	public:
-		HttpResponseHeader(int response_code,int major = 1,int minor = 1);
+		HttpResponseHeader(int zresponse_code,int zmajor = 1,int zminor = 1);
 		HttpResponseHeader(const HttpResponseHeader & hdr);
 		virtual ~HttpResponseHeader();
 		
