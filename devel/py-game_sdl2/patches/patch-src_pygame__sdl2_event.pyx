$NetBSD: patch-src_pygame__sdl2_event.pyx,v 1.1 2025/05/12 05:18:50 ryoon Exp $

--- src/pygame_sdl2/event.pyx.orig	2025-05-11 13:44:10.220009277 +0000
+++ src/pygame_sdl2/event.pyx
@@ -332,7 +332,7 @@ cdef object get_events(kinds):
     The lock must be held when calling this function.
     """
 
-    if isinstance(kinds, (int, long)):
+    if isinstance(kinds, int):
         kinds = [ kinds ]
 
     global event_queue
@@ -459,7 +459,7 @@ def set_blocked(t=None):
     if t == None:
         for et in event_names.keys():
             SDL_EventState(et, SDL_ENABLE)
-    elif isinstance(t, (int, long)):
+    elif isinstance(t, int):
         SDL_EventState(t, SDL_IGNORE)
     else:
         for et in t:
@@ -469,7 +469,7 @@ def set_allowed(t=None):
     if t == None:
         for et in event_names.keys():
             SDL_EventState(et, SDL_IGNORE)
-    elif isinstance(t, (int, long)):
+    elif isinstance(t, int):
         SDL_EventState(t, SDL_ENABLE)
     else:
         for et in t:
