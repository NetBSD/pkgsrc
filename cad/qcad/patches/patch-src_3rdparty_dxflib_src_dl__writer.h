$NetBSD: patch-src_3rdparty_dxflib_src_dl__writer.h,v 1.1 2016/08/30 10:56:04 plunky Exp $

apply fix for PR 45392

--- src/3rdparty/dxflib/src/dl_writer.h.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/dxflib/src/dl_writer.h
@@ -36,6 +36,7 @@
 #pragma once
 #endif // _MSC_VER > 1000

+#include <cstring>
 #include <iostream>
 #include <algorithm>
