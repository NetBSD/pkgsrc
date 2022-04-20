$NetBSD: patch-src_screen.c,v 1.1 2022/04/20 17:14:20 nia Exp $

CVE-2018-20786 fix from vim cd929f7ba8cc5b6d6dcf35c8b34124e969fed6b8

--- src/screen.c.orig	2022-03-13 06:09:38.851039573 +0000
+++ src/screen.c
@@ -94,8 +94,7 @@ static ScreenCell *realloc_buffer(VTermS
     }
   }
 
-  if(buffer)
-    vterm_allocator_free(screen->vt, buffer);
+  vterm_allocator_free(screen->vt, buffer);
 
   return new_buffer;
 }
@@ -517,8 +516,7 @@ static int resize(int new_rows, int new_
   screen->rows = new_rows;
   screen->cols = new_cols;
 
-  if(screen->sb_buffer)
-    vterm_allocator_free(screen->vt, screen->sb_buffer);
+  vterm_allocator_free(screen->vt, screen->sb_buffer);
 
   screen->sb_buffer = vterm_allocator_malloc(screen->vt, sizeof(VTermScreenCell) * new_cols);
 
@@ -619,13 +617,19 @@ static VTermStateCallbacks state_cbs = {
   .setlineinfo = &setlineinfo,
 };
 
+/*
+ * Allocate a new screen and return it.
+ * Return NULL when out of memory.
+ */
 static VTermScreen *screen_new(VTerm *vt)
 {
   VTermState *state = vterm_obtain_state(vt);
-  if(!state)
+  if (state == NULL)
     return NULL;
 
   VTermScreen *screen = vterm_allocator_malloc(vt, sizeof(VTermScreen));
+  if (screen == NULL)
+    return NULL;
   int rows, cols;
 
   vterm_get_size(vt, &rows, &cols);
@@ -644,10 +648,13 @@ static VTermScreen *screen_new(VTerm *vt
   screen->cbdata    = NULL;
 
   screen->buffers[0] = realloc_buffer(screen, NULL, rows, cols);
-
   screen->buffer = screen->buffers[0];
-
   screen->sb_buffer = vterm_allocator_malloc(screen->vt, sizeof(VTermScreenCell) * cols);
+  if (screen->buffer == NULL || screen->sb_buffer == NULL)
+  {
+    vterm_screen_free(screen);
+    return NULL;
+  }
 
   vterm_state_set_callbacks(screen->state, &state_cbs, screen);
 
@@ -657,11 +664,8 @@ static VTermScreen *screen_new(VTerm *vt
 INTERNAL void vterm_screen_free(VTermScreen *screen)
 {
   vterm_allocator_free(screen->vt, screen->buffers[0]);
-  if(screen->buffers[1])
-    vterm_allocator_free(screen->vt, screen->buffers[1]);
-
+  vterm_allocator_free(screen->vt, screen->buffers[1]);
   vterm_allocator_free(screen->vt, screen->sb_buffer);
-
   vterm_allocator_free(screen->vt, screen);
 }
 
