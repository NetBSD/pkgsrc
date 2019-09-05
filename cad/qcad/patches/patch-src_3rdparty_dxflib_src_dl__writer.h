$NetBSD: patch-src_3rdparty_dxflib_src_dl__writer.h,v 1.2 2019/09/05 13:39:10 nia Exp $

apply fix for PR 45392

--- src/3rdparty/dxflib/src/dl_writer.h.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/3rdparty/dxflib/src/dl_writer.h
@@ -36,6 +36,7 @@
 #pragma once
 #endif // _MSC_VER > 1000
 
+#include <cstring>
 #include <iostream>
 #include <algorithm>
 
