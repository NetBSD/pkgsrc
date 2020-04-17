$NetBSD: patch-policy_common_element.cc,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- policy/common/element.cc.orig	2020-04-16 14:40:39.438101634 +0000
+++ policy/common/element.cc
@@ -89,7 +89,7 @@ ElemCom32::ElemCom32(const char* c_str) 
     }
 
     int len = strlen(c_str);
-    char *colon = strstr(c_str, ":");
+    const char *colon = strstr(c_str, ":");
 
     if(len > 0 && colon != NULL) {
 	uint32_t msw, lsw;
