$NetBSD: patch-src_ptex_PtexWriter.cpp,v 1.1 2017/02/15 00:54:50 joerg Exp $

--- src/ptex/PtexWriter.cpp.orig	2017-02-15 00:33:54.858207702 +0000
+++ src/ptex/PtexWriter.cpp
@@ -63,6 +63,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <algorithm>
 #include <iostream>
 #include <sstream>
