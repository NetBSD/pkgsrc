$NetBSD: patch-netwerk_protocol_http_Http2Session.cpp,v 1.2 2017/01/22 12:27:22 ryoon Exp $

--- netwerk/protocol/http/Http2Session.cpp.orig	2016-07-25 12:12:07.000000000 +0000
+++ netwerk/protocol/http/Http2Session.cpp
@@ -3521,8 +3521,8 @@ Http2Session::ConfirmTLSProfile()
     LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to DH %d < 2048\n",
           this, keybits));
     RETURN_SESSION_ERROR(this, INADEQUATE_SECURITY);
-  } else if (kea == ssl_kea_ecdh && keybits < 256) { // 256 bits is "security level" of 128
-    LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to ECDH %d < 256\n",
+  } else if (kea == ssl_kea_ecdh && keybits < 224) { // see rfc7540 9.2.1.
+    LOG3(("Http2Session::ConfirmTLSProfile %p FAILED due to ECDH %d < 224\n",
           this, keybits));
     RETURN_SESSION_ERROR(this, INADEQUATE_SECURITY);
   }
