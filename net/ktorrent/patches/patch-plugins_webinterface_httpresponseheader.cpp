$NetBSD: patch-plugins_webinterface_httpresponseheader.cpp,v 1.1 2012/09/03 10:14:44 marino Exp $

Fix "anachronistic old style base class initializer" error

--- plugins/webinterface/httpresponseheader.cpp.orig	2012-06-12 10:09:58.000000000 +0000
+++ plugins/webinterface/httpresponseheader.cpp
@@ -33,9 +33,11 @@ namespace kt
 		return QString::null;
 	}
 	
-	HttpResponseHeader::HttpResponseHeader(int response_code,int major,int minor) 
-		: response_code(response_code),major(major),minor(minor)
+	HttpResponseHeader::HttpResponseHeader(int zresponse_code,int zmajor,int zminor) 
 	{
+		response_code = zresponse_code;
+		major = zmajor;
+		minor = zminor;
 	}
 	
 	HttpResponseHeader::HttpResponseHeader(const HttpResponseHeader & hdr)
