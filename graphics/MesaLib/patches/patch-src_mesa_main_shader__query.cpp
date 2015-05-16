$NetBSD: patch-src_mesa_main_shader__query.cpp,v 1.1 2015/05/16 16:39:52 tnn Exp $

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

diff --git a/src/mesa/main/shader_query.cpp b/src/mesa/main/shader_query.cpp
index bc6fec5..22d9e0f 100644
--- src/mesa/main/shader_query.cpp
+++ src/mesa/main/shader_query.cpp
@@ -68,7 +68,7 @@ _mesa_BindAttribLocation(GLhandleARB program, GLuint index,
    GET_CURRENT_CONTEXT(ctx);
 
    struct gl_shader_program *const shProg =
-      _mesa_lookup_shader_program_err(ctx, program, "glBindAttribLocation");
+      _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glBindAttribLocation");
    if (!shProg)
       return;
 
@@ -136,7 +136,7 @@ _mesa_GetActiveAttrib(GLhandleARB program, GLuint desired_index,
       return;
    }
 
-   shProg = _mesa_lookup_shader_program_err(ctx, program, "glGetActiveAttrib");
+   shProg = _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glGetActiveAttrib");
    if (!shProg)
       return;
 
@@ -250,7 +250,7 @@ _mesa_GetAttribLocation(GLhandleARB program, const GLcharARB * name)
 {
    GET_CURRENT_CONTEXT(ctx);
    struct gl_shader_program *const shProg =
-      _mesa_lookup_shader_program_err(ctx, program, "glGetAttribLocation");
+      _mesa_lookup_shader_program_err(ctx, (GLuint)(uintptr_t)program, "glGetAttribLocation");
 
    if (!shProg) {
       return -1;
