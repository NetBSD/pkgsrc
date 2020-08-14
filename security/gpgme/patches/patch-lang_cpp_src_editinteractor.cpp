$NetBSD: patch-lang_cpp_src_editinteractor.cpp,v 1.1 2020/08/14 10:32:43 tnn Exp $

editinteractor.cpp:181:29: error: use of undeclared identifier 'getenv'

--- lang/cpp/src/editinteractor.cpp.orig	2020-07-15 10:14:17.000000000 +0000
+++ lang/cpp/src/editinteractor.cpp
@@ -41,6 +41,7 @@
 
 #include <cerrno>
 #include <cstring>
+#include <cstdlib>
 
 #ifndef GPG_ERR_ALREADY_SIGNED
 # define GPG_ERR_ALREADY_SIGNED GPG_ERR_USER_1
