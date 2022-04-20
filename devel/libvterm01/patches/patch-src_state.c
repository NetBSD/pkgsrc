$NetBSD: patch-src_state.c,v 1.1 2022/04/20 17:14:20 nia Exp $

CVE-2018-20786 fix from vim cd929f7ba8cc5b6d6dcf35c8b34124e969fed6b8

--- src/state.c.orig	2022-03-12 21:10:57.446471266 +0000
+++ src/state.c
@@ -52,6 +52,8 @@ static VTermState *vterm_state_new(VTerm
 {
   VTermState *state = vterm_allocator_malloc(vt, sizeof(VTermState));
 
+  if (state == NULL)
+    return NULL;
   state->vt = vt;
 
   state->rows = vt->rows;
@@ -1697,12 +1699,18 @@ static const VTermParserCallbacks parser
   .resize  = on_resize,
 };
 
+/*
+ * Return the existing state or create a new one.
+ * Returns NULL when out of memory.
+ */
 VTermState *vterm_obtain_state(VTerm *vt)
 {
   if(vt->state)
     return vt->state;
 
   VTermState *state = vterm_state_new(vt);
+  if (state == NULL)
+    return NULL;
   vt->state = state;
 
   state->combine_chars_size = 16;
