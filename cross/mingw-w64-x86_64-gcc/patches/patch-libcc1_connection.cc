$NetBSD: patch-libcc1_connection.cc,v 1.1 2020/03/27 20:55:39 joerg Exp $

--- libcc1/connection.cc.orig	2020-03-27 17:34:16.253197163 +0000
+++ libcc1/connection.cc
@@ -21,6 +21,7 @@ along with GCC; see the file COPYING3.  
 #include <string>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/select.h>
 #include <string.h>
 #include <errno.h>
 #include "marshall.hh"
