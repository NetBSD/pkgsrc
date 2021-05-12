$NetBSD: patch-src_EbmlString.cpp,v 1.1 2021/05/12 04:03:50 mcf Exp $

Fix build with gcc 11.

Upstream: https://github.com/Matroska-Org/libebml/commit/f0bfd53647961e799a43d918c46cf3b6bff89806

--- src/EbmlString.cpp.orig	Wed May 12 03:52:00 2021
+++ src/EbmlString.cpp
@@ -34,6 +34,7 @@
   \author Steve Lhomme     <robux4 @ users.sf.net>
 */
 #include <cassert>
+#include <limits>
 
 #include "ebml/EbmlString.h"
 
