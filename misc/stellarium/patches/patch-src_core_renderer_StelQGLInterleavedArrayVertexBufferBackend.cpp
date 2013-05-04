$NetBSD: patch-src_core_renderer_StelQGLInterleavedArrayVertexBufferBackend.cpp,v 1.1 2013/05/04 12:59:47 joerg Exp $

--- src/core/renderer/StelQGLInterleavedArrayVertexBufferBackend.cpp.orig	2013-05-04 00:37:31.000000000 +0000
+++ src/core/renderer/StelQGLInterleavedArrayVertexBufferBackend.cpp
@@ -21,7 +21,7 @@
 #include "StelProjector.hpp"
 #include "StelQGLInterleavedArrayVertexBufferBackend.hpp"
 #include "StelQGLIndexBuffer.hpp"
-
+#include <cstdlib>
 
 StelQGLInterleavedArrayVertexBufferBackend::
 StelQGLInterleavedArrayVertexBufferBackend
