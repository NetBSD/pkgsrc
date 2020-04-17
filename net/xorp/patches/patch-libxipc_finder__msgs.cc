$NetBSD: patch-libxipc_finder__msgs.cc,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- libxipc/finder_msgs.cc.orig	2020-04-16 14:37:03.894247926 +0000
+++ libxipc/finder_msgs.cc
@@ -228,8 +228,8 @@ ParsedFinderXrlResponse::ParsedFinderXrl
     : ParsedFinderMessageBase(data, FinderXrlResponse::c_type), _xrl_args(0)
 {
     data += bytes_parsed();
-    char* p0 = strstr(data, "/");
-    char* p1 = strstr(data, "\n");
+    const char* p0 = strstr(data, "/");
+    const char* p1 = strstr(data, "\n");
     if (p0 == 0 || p1 == 0) {
 	xorp_throw(BadFinderMessageFormat, "XrlError not present");
     }
