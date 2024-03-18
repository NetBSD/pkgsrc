$NetBSD: patch-libs_ardour_audiofile__tagger.cc,v 1.1 2024/03/18 15:36:15 ryoon Exp $

From archlinux.

--- libs/ardour/audiofile_tagger.cc.orig	2024-02-04 01:44:20.664892743 +0000
+++ libs/ardour/audiofile_tagger.cc
@@ -34,6 +34,8 @@
 #include <taglib/taglib.h>
 #include <taglib/xiphcomment.h>
 
+#include <iostream>
+
 /* Convert string to TagLib::String */
 #define TL_STR(string) TagLib::String ((string).c_str(), TagLib::String::UTF8)
 
