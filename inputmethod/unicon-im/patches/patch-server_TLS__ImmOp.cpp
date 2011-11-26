$NetBSD: patch-server_TLS__ImmOp.cpp,v 1.1 2011/11/26 17:13:30 joerg Exp $

--- server/TLS_ImmOp.cpp.orig	2011-11-26 03:22:12.000000000 +0000
+++ server/TLS_ImmOp.cpp
@@ -1,4 +1,4 @@
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <string.h>
 #include <dlfcn.h>
