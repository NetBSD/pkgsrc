$NetBSD: patch-util_dbus__socket__transformer_main.cpp,v 1.1 2014/09/24 14:57:29 jperkin Exp $

Include strings.h for bzero().

--- util/dbus_socket_transformer/main.cpp.orig	2013-12-07 18:45:39.000000000 +0000
+++ util/dbus_socket_transformer/main.cpp
@@ -30,6 +30,7 @@
 #include <sstream>
 #include <unistd.h>
 #include <string.h>
+#include <strings.h>
 
 #ifndef HAVE_MSG_NOSIGNAL
 #define MSG_NOSIGNAL 0
