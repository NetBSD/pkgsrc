$NetBSD: patch-src_core_renderer_StelQGLArrayVertexBufferBackend.cpp,v 1.1 2013/05/04 12:59:47 joerg Exp $

--- src/core/renderer/StelQGLArrayVertexBufferBackend.cpp.orig	2013-05-04 00:38:04.000000000 +0000
+++ src/core/renderer/StelQGLArrayVertexBufferBackend.cpp
@@ -20,7 +20,7 @@
 #include "StelProjector.hpp"
 #include "StelQGLArrayVertexBufferBackend.hpp"
 #include "StelQGLIndexBuffer.hpp"
-
+#include <cstdlib>
 
 StelQGLArrayVertexBufferBackend::
 StelQGLArrayVertexBufferBackend(const PrimitiveType type, 
