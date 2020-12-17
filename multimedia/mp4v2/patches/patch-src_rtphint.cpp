$NetBSD: patch-src_rtphint.cpp,v 1.1 2020/12/17 09:16:42 triaxx Exp $

Fix forbidden comparison between pointer and integer (Github pull request #42).

--- src/rtphint.cpp.orig	2020-12-07 23:16:32.000000000 +0000
+++ src/rtphint.cpp
@@ -339,7 +339,7 @@ void MP4RtpHintTrack::GetPayload(
                 pSlash = strchr(pSlash, '/');
                 if (pSlash != NULL) {
                     pSlash++;
-                    if (pSlash != '\0') {
+                    if (*pSlash != '\0') {
                         length = (uint32_t)strlen(pRtpMap) - (pSlash - pRtpMap);
                         *ppEncodingParams = (char *)MP4Calloc(length + 1);
                         strncpy(*ppEncodingParams, pSlash, length);
