$NetBSD: patch-lib_net_CTCPSocket.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/net/CTCPSocket.cpp.orig	2011-11-22 19:36:24.000000000 +0000
+++ lib/net/CTCPSocket.cpp
@@ -23,6 +23,7 @@
 #include "IEventJob.h"
 #include "CArch.h"
 #include "XArch.h"
+#include <stdlib.h>
 #include <string.h>
 
 //
