$NetBSD: patch-Rendering_GL2PSOpenGL2_vtkOpenGLGL2PSHelperImpl.cxx,v 1.1 2025/02/24 17:23:20 adam Exp $

Missing vtk_glad.h include.
https://gitlab.kitware.com/vtk/vtk/-/issues/19561

--- Rendering/GL2PSOpenGL2/vtkOpenGLGL2PSHelperImpl.cxx.orig	2025-02-24 13:06:25.803916103 +0000
+++ Rendering/GL2PSOpenGL2/vtkOpenGLGL2PSHelperImpl.cxx
@@ -21,6 +21,7 @@
 #include "vtkTextRenderer.h"
 #include "vtkTransformFeedback.h"
 
+#include "vtk_glad.h"
 #include "vtk_gl2ps.h"
 
 #include <algorithm>
