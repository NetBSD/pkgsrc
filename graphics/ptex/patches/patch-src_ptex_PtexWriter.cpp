$NetBSD: patch-src_ptex_PtexWriter.cpp,v 1.2 2023/11/07 17:56:56 nros Exp $

unistd.h needed for declaration of unlink

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
