$NetBSD: patch-lib_perfdata_influxdbwriter.cpp,v 1.1 2021/01/15 00:37:17 wiz Exp $

Support Boost 1.74 when setting HTTP headers

Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/perfdata/influxdbwriter.cpp.orig	2020-08-03 15:43:47.000000000 +0200
+++ lib/perfdata/influxdbwriter.cpp	2021-01-14 19:25:50.874644996 +0100
@@ -505,7 +505,7 @@
 	request.set(http::field::host, url->GetHost() + ":" + url->GetPort());
 
 	request.body() = body;
-	request.set(http::field::content_length, request.body().size());
+	request.content_length(request.body().size());
 
 	try {
 		if (stream.first) {
