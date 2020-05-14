$NetBSD: patch-libhylafax_FaxRecvInfo.c++,v 1.1 2020/05/14 19:17:45 joerg Exp $

--- libhylafax/FaxRecvInfo.c++.orig	2020-05-12 14:59:48.960689473 +0000
+++ libhylafax/FaxRecvInfo.c++
@@ -112,7 +112,7 @@ FaxRecvInfo::decode(const char* cp)
     if (cp == NULL || cp[1] != ',' || cp[2] != '"')
 	return (false);
     u_int i = 0;
-    while (cp+2 != '\0') {
+    while (cp[2] != '\0') {
 	callid[i] = cp+3;		// +1 for "/+1 for ,/+1 for "
 	if (*cp == '\"') break;
 	callid[i].resize(callid[i].next(0,'"'));
