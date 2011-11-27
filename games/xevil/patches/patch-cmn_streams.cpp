$NetBSD: patch-cmn_streams.cpp,v 1.1 2011/11/27 19:43:33 joerg Exp $

--- cmn/streams.cpp.orig	2011-11-27 02:22:01.000000000 +0000
+++ cmn/streams.cpp
@@ -31,7 +31,7 @@
 #include "utils.h"
 #include "neth.h" // needed for recv, send, recvfrom, sendto
 
-#include <iostream.h>
+#include <iostream>
 
 #include "streams.h"
 #include "xetp.h" // yuck, need this for XETP::versionStr
