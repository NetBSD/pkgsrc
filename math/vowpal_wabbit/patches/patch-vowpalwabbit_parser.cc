$NetBSD: patch-vowpalwabbit_parser.cc,v 1.1 2016/09/18 07:08:19 dholland Exp $

Use standard headers.

--- vowpalwabbit/parser.cc~	2016-06-21 18:37:43.000000000 +0000
+++ vowpalwabbit/parser.cc
@@ -34,7 +34,7 @@ int getpid()
 #endif
 #include <boost/program_options.hpp>
 
-#ifdef __FreeBSD__
+#ifndef _WIN32
 #include <netinet/in.h>
 #endif
 
