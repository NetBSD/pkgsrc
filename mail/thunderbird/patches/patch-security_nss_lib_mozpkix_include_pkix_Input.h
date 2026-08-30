$NetBSD: patch-security_nss_lib_mozpkix_include_pkix_Input.h,v 1.1 2026/08/30 10:26:06 ryoon Exp $

* Do not conflict with Success macro in X11/X.h.
  This is not for Firefox.

--- security/nss/lib/mozpkix/include/pkix/Input.h.orig	2026-08-20 05:49:40.037496789 +0000
+++ security/nss/lib/mozpkix/include/pkix/Input.h
@@ -24,6 +24,8 @@
 
 #ifndef mozilla_pkix_Input_h
 #define mozilla_pkix_Input_h
+#pragma push_macro("Success")
+#undef Success
 
 #include <algorithm>
 
@@ -306,5 +308,4 @@ inline bool InputContains(const Input& input, uint8_t 
 }
 }  // namespace pkix
 }  // namespace mozilla
-
 #endif  // mozilla_pkix_Input_h
