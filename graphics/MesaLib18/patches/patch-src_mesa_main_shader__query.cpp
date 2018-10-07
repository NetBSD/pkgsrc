$NetBSD: patch-src_mesa_main_shader__query.cpp,v 1.1 2018/10/07 23:49:31 ryoon Exp $

https://bugs.freedesktop.org/show_bug.cgi?id=66346

From c4a1fec68d2508ff0c4fc2831465aca8c4ca783a Mon Sep 17 00:00:00 2001
From: Julien Isorce <j.isorce@samsung.com>
Date: Wed, 22 Apr 2015 23:04:42 +0100
Subject: [PATCH 1/2] shader_query: convert GLhandleARB to uintptr_t before
 troncating to GLuint

Fixes compiler error on OSX as GLhandleARB is defined as void* if __APPLE__.

https://bugs.freedesktop.org/show_bug.cgi?id=66346
---
 src/mesa/main/shader_query.cpp | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

--- src/mesa/main/shader_query.cpp.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/mesa/main/shader_query.cpp
@@ -70,7 +70,12 @@ _mesa_BindAttribLocation(GLuint program,
    GET_CURRENT_CONTEXT(ctx);
 
    struct gl_shader_program *const shProg =
+#if defined(__APPLE__)
+      _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glBindAttribLocation");
+#else
       _mesa_lookup_shader_program_err(ctx, program, "glBindAttribLocation");
+#endif
+
    if (!shProg)
       return;
 
@@ -114,7 +119,12 @@ _mesa_GetActiveAttrib(GLuint program, GL
       return;
    }
 
+#if defined(__APPLE__)
+   shProg = _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glGetActiveAttrib");
+#else
    shProg = _mesa_lookup_shader_program_err(ctx, program, "glGetActiveAttrib");
+#endif
+
    if (!shProg)
       return;
 
@@ -159,7 +169,12 @@ _mesa_GetAttribLocation(GLuint program,
 {
    GET_CURRENT_CONTEXT(ctx);
    struct gl_shader_program *const shProg =
+
+#if defined(__APPLE__)
+      _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glGetAttribLocation");
+#else
       _mesa_lookup_shader_program_err(ctx, program, "glGetAttribLocation");
+#endif
 
    if (!shProg) {
       return -1;
