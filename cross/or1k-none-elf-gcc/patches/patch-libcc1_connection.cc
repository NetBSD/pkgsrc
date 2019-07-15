$NetBSD: patch-libcc1_connection.cc,v 1.1 2019/07/15 05:59:13 maya Exp $

--- libcc1/connection.cc.orig	2019-01-01 12:31:55.000000000 +0000
+++ libcc1/connection.cc
@@ -23,6 +23,7 @@ along with GCC; see the file COPYING3.
 #include <sys/types.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/select.h>
 #include "marshall.hh"
 #include "connection.hh"
 #include "rpc.hh"
