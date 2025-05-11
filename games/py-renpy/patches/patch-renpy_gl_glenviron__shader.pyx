$NetBSD: patch-renpy_gl_glenviron__shader.pyx,v 1.1 2025/05/11 14:08:33 ryoon Exp $

--- renpy/gl/glenviron_shader.pyx.orig	2025-03-17 02:58:30.292934400 +0000
+++ renpy/gl/glenviron_shader.pyx
@@ -278,7 +278,9 @@ def check_status(shader, handle, type):
     else:
         glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &log_length)
 
-    log = ' ' * log_length
+    pylog = ' ' * log_length
+    pyulog = pylog.encode('UTF-8')
+    cdef char*log = pyulog
 
     if shader:
         glGetShaderInfoLog(handle, log_length, &log_length, <char *> log)
