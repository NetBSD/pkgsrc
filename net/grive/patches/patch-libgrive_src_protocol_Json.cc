$NetBSD: patch-libgrive_src_protocol_Json.cc,v 1.1.1.1 2014/06/06 14:57:00 abs Exp $

Update for json-c 0.11 and later

--- libgrive/src/protocol/Json.cc.orig	2013-05-02 16:40:04.000000000 +0000
+++ libgrive/src/protocol/Json.cc
@@ -29,8 +29,8 @@
 	#pragma warning(push)
 	#pragma warning(disable: 4005)
 #endif
-#include <json/json_tokener.h>
-#include <json/linkhash.h>
+#include <json-c/json_tokener.h>
+#include <json-c/linkhash.h>
 #ifdef _MSC_VER
 	#pragma warning(pop)
 #endif
