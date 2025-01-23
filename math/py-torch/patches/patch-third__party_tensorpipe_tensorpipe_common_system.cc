$NetBSD: patch-third__party_tensorpipe_tensorpipe_common_system.cc,v 1.1 2025/01/23 14:31:16 ryoon Exp $

* Retern fake boot ID under NetBSD.

--- third_party/tensorpipe/tensorpipe/common/system.cc.orig	2025-01-21 15:51:15.145360508 +0000
+++ third_party/tensorpipe/tensorpipe/common/system.cc
@@ -101,7 +101,10 @@ std::string getPathForLinuxNamespace(Lin
   }
   return oss.str();
 }
-
+#elif defined(__NetBSD__)
+optional<std::string> getBootIDInternal() {
+  return std::string("00000000-0000-0000-0000-000000000000");
+}
 #endif
 
 } // namespace
