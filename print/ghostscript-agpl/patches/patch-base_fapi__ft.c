$NetBSD: patch-base_fapi__ft.c,v 1.1.2.2 2020/10/23 11:17:44 spz Exp $

Build with FreeType 2.10.3.

--- base/fapi_ft.c.orig	2020-09-14 13:40:08.000000000 +0000
+++ base/fapi_ft.c
@@ -125,7 +125,7 @@ static void
 delete_inc_int_info(gs_fapi_server * a_server,
                     FT_IncrementalRec * a_inc_int_info);
 
-FT_CALLBACK_DEF(void *)
+static void *
 FF_alloc(FT_Memory memory, long size)
 {
     gs_memory_t *mem = (gs_memory_t *) memory->user;
@@ -133,7 +133,7 @@ FF_alloc(FT_Memory memory, long size)
     return (gs_malloc(mem, size, 1, "FF_alloc"));
 }
 
-FT_CALLBACK_DEF(void *)
+static void *
     FF_realloc(FT_Memory memory, long cur_size, long new_size, void *block)
 {
     gs_memory_t *mem = (gs_memory_t *) memory->user;
@@ -153,7 +153,7 @@ FT_CALLBACK_DEF(void *)
     return (tmp);
 }
 
-FT_CALLBACK_DEF(void)
+static void
     FF_free(FT_Memory memory, void *block)
 {
     gs_memory_t *mem = (gs_memory_t *) memory->user;
