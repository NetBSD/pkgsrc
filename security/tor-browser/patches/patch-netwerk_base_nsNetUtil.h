$NetBSD: patch-netwerk_base_nsNetUtil.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- netwerk/base/nsNetUtil.h.orig	2015-05-04 00:43:34.000000000 +0000
+++ netwerk/base/nsNetUtil.h
@@ -13,6 +13,7 @@
 #include "nsMemory.h"
 #include "nsCOMPtr.h"
 #include "prio.h" // for read/write flags, permissions, etc.
+#include "prnetdb.h"
 #include "nsHashKeys.h"
 
 #include "plstr.h"
@@ -2828,6 +2829,26 @@ NS_IsSrcdocChannel(nsIChannel *aChannel)
 bool NS_IsReasonableHTTPHeaderValue(const nsACString& aValue);
 
 /**
+ * Return a host endian value decoded from network byte order,
+ * accessed in an alignement safe way.
+ */
+inline uint16_t NS_decodeN16(const void *bytes)
+{
+    uint16_t tmp;
+
+    memcpy(&tmp, bytes, sizeof tmp);
+    return PR_ntohs(tmp);
+}
+
+inline uint32_t NS_decodeN32(const void *bytes)
+{
+    uint32_t tmp;
+
+    memcpy(&tmp, bytes, sizeof tmp);
+    return PR_ntohl(tmp);
+}
+
+/**
  * Return true if the given string is a valid HTTP token per RFC 2616 section
  * 2.2.
  */
