$NetBSD: patch-src_engine_uri.cpp,v 1.1 2017/08/25 20:04:07 joerg Exp $

Moved to libfilezilla.

--- src/engine/uri.cpp.orig	2017-02-11 13:27:28.000000000 +0000
+++ src/engine/uri.cpp
@@ -2,6 +2,7 @@
 
 #include "uri.h"
 
+#include <libfilezilla/encode.hpp>
 #include <libfilezilla/iputils.hpp>
 
 namespace fz {
@@ -223,6 +224,7 @@ bool uri::empty() const
 	return host_.empty() && path_.empty();
 }
 
+#if 0
 std::string percent_encode(std::string const& s, bool keep_slashes)
 {
 	std::string ret;
@@ -293,5 +295,6 @@ std::string percent_decode(std::string c
 
 	return ret;
 }
+#endif
 
 }
