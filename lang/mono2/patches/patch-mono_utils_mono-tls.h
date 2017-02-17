$NetBSD: patch-mono_utils_mono-tls.h,v 1.1 2017/02/17 17:07:32 joerg Exp $

Thread destructor will still try to update the key, even after destructor.
Prefer leaking memory to crashes.

--- mono/utils/mono-tls.h.orig	2017-02-16 23:12:51.591610250 +0000
+++ mono/utils/mono-tls.h
@@ -38,7 +38,7 @@ mono_native_tls_alloc (MonoNativeTlsKey 
 static inline void
 mono_native_tls_free (MonoNativeTlsKey key)
 {
-	pthread_key_delete (key);
+	//pthread_key_delete (key);
 }
 
 static inline int
