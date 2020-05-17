$NetBSD: patch-src_extension_implementation_script.cpp,v 1.1 2020/05/17 00:38:47 tnn Exp $

Replace python3 interpreter.

--- src/extension/implementation/script.cpp.orig	2020-05-01 13:18:52.000000000 +0000
+++ src/extension/implementation/script.cpp
@@ -77,10 +77,10 @@ const std::map<std::string, Script::inte
         { "python",  {"python-interpreter",  {"pythonw"           }}},
 #elif defined __APPLE__
         { "perl",    {"perl-interpreter",    {"perl"              }}},
-        { "python",  {"python-interpreter",  {"python3"           }}},
+        { "python",  {"python-interpreter",  {"@PYTHONBIN@", "python3"           }}},
 #else
         { "perl",    {"perl-interpreter",    {"perl"              }}},
-        { "python",  {"python-interpreter",  {"python3", "python" }}},
+        { "python",  {"python-interpreter",  {"@PYTHONBIN@", "python3", "python" }}},
 #endif
         { "python2", {"python2-interpreter", {"python2", "python" }}},
         { "ruby",    {"ruby-interpreter",    {"ruby"    }}},
