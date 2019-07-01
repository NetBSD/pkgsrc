$NetBSD: patch-src_supertux_main.cpp,v 1.1 2019/07/01 15:13:20 nia Exp $

terminate called after throwing an instance of 'std::runtime_error'
  what():  locale::facet::_S_create_c_locale name not valid

Program received signal SIGABRT, Aborted.

[1]   Abort trap (core dumped) supertux2

--- src/supertux/main.cpp.orig	2018-12-23 19:11:32.000000000 +0000
+++ src/supertux/main.cpp
@@ -548,11 +548,6 @@ Main::run(int argc, char** argv)
 	_wfreopen(w_errpath.c_str(), L"a", stderr);
 #endif
 
-  // Create and install global locale
-  std::locale::global(boost::locale::generator().generate(""));
-  // Make boost.filesystem use it
-  boost::filesystem::path::imbue(std::locale());
-
   int result = 0;
 
   try
