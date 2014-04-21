$NetBSD: patch-src_id3lib_c__wrapper.cpp,v 1.1 2014/04/21 18:16:41 joerg Exp $

--- src/id3lib/c_wrapper.cpp.orig	2014-04-19 13:19:00.000000000 +0000
+++ src/id3lib/c_wrapper.cpp
@@ -31,7 +31,6 @@
 #include <id3.h>
 #include <id3/field.h>
 #include <id3/tag.h>
-#include "id3_bugfix.h"
 
 #ifdef __cplusplus
 extern "C"
