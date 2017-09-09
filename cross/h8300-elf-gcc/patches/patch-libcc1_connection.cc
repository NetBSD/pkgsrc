$NetBSD: patch-libcc1_connection.cc,v 1.1 2017/09/09 15:15:04 dholland Exp $

Use standard headers. (for select())

--- libcc1/connection.cc~	2014-11-13 10:22:22.000000000 +0000
+++ libcc1/connection.cc
@@ -21,6 +21,7 @@ along with GCC; see the file COPYING3.  
 #include <string>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <string.h>
 #include <errno.h>
 #include "marshall.hh"
