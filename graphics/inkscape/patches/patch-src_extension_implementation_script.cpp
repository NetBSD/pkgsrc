$NetBSD: patch-src_extension_implementation_script.cpp,v 1.2 2021/07/02 06:59:15 wiz Exp $

Replace python3 interpreter.

--- src/extension/implementation/script.cpp.orig	2021-05-17 19:26:40.000000000 +0000
+++ src/extension/implementation/script.cpp
@@ -82,10 +82,10 @@ const std::map<std::string, Script::inte
     { "python",  {"python-interpreter",  {"pythonw"           }}},
 #elif defined __APPLE__
     { "perl",    {"perl-interpreter",    {"perl"              }}},
-    { "python",  {"python-interpreter",  {"python3"           }}},
+    { "python",  {"python-interpreter",  {"@PYTHONBIN@"           }}},
 #else
     { "perl",    {"perl-interpreter",    {"perl"              }}},
-    { "python",  {"python-interpreter",  {"python3", "python" }}},
+    { "python",  {"python-interpreter",  {"@PYTHONBIN@", "python" }}},
 #endif
     { "python2", {"python2-interpreter", {"python2", "python" }}},
     { "ruby",    {"ruby-interpreter",    {"ruby"    }}},
