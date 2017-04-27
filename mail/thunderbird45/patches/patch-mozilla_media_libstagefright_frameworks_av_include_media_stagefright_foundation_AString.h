$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_include_media_stagefright_foundation_AString.h,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h
@@ -18,6 +18,7 @@
 
 #define A_STRING_H_
 
+#include <cctype>
 #include <sys/types.h>
 
 namespace stagefright {
