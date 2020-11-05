$NetBSD: patch-src_lib_libcdr__utils.cpp,v 1.1 2020/11/05 09:17:53 ryoon Exp $

* Fix build with textproc/icu-68.1.

--- src/lib/libcdr_utils.cpp.orig	2020-02-02 15:30:44.000000000 +0000
+++ src/lib/libcdr_utils.cpp
@@ -108,7 +108,7 @@ static unsigned short getEncoding(const 
     csd = ucsdet_open(&status);
     if (U_FAILURE(status) || !csd)
       return 0;
-    ucsdet_enableInputFilter(csd, TRUE);
+    ucsdet_enableInputFilter(csd, true);
     ucsdet_setText(csd, (const char *)buffer, bufferLength, &status);
     if (U_FAILURE(status))
       throw libcdr::EncodingException();
