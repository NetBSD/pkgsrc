$NetBSD: patch-lib_mp4v2_rtphint.cpp,v 1.1 2017/12/19 10:08:14 markd Exp $

gcc7 fix

--- lib/mp4v2/rtphint.cpp.orig	2007-04-30 20:29:28.000000000 +0000
+++ lib/mp4v2/rtphint.cpp
@@ -342,7 +342,7 @@ void MP4RtpHintTrack::GetPayload(
 			  pSlash = strchr(pSlash, '/');
 			  if (pSlash != NULL) {
 			    pSlash++;
-			    if (pSlash != '\0') {
+			    if (*pSlash != '\0') {
 			      length = strlen(pRtpMap) - (pSlash - pRtpMap);
 			      *ppEncodingParams = (char *)MP4Calloc(length + 1);
 			      strncpy(*ppEncodingParams, pSlash, length);
