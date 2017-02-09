$NetBSD: patch-src_ptex.imageio_ptex_PtexWriter.cpp,v 1.1 2017/02/09 00:21:34 joerg Exp $

--- src/ptex.imageio/ptex/PtexWriter.cpp.orig	2017-02-08 21:33:00.513673134 +0000
+++ src/ptex.imageio/ptex/PtexWriter.cpp
@@ -66,9 +66,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <algorithm>
 #include <iostream>
 #include <sstream>
-#if defined (__FreeBSD__)
 #include <unistd.h>
-#endif
 
 #include "OpenImageIO/filesystem.h"
 
