$NetBSD: patch-src_lib_log_logger__level__impl.cc,v 1.1 2025/12/28 15:13:53 adam Exp $

Add missing include.

--- src/lib/log/logger_level_impl.cc.orig	2025-12-28 15:01:51.625451515 +0000
+++ src/lib/log/logger_level_impl.cc
@@ -10,6 +10,7 @@
 #include <string.h>
 #include <iostream>
 #include <boost/lexical_cast.hpp>
+#include <boost/static_assert.hpp>
 
 #include <log4cplus/logger.h>
 
