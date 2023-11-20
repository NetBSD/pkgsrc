$NetBSD: patch-kivy_core_window___window__sdl2.pyx,v 1.1 2023/11/20 06:36:47 wiz Exp $

https://github.com/kivy/kivy/pull/8326/files

--- kivy/core/window/_window_sdl2.pyx.orig	2023-11-20 06:24:57.914793792 +0000
+++ kivy/core/window/_window_sdl2.pyx
@@ -263,7 +263,7 @@ cdef class _WindowSDL2Storage:
         for joy_i in range(SDL_NumJoysticks()):
             SDL_JoystickOpen(joy_i)
 
-        SDL_SetEventFilter(_event_filter, <void *>self)
+        SDL_SetEventFilter(<SDL_EventFilter *>_event_filter, <void *>self)
 
         SDL_EventState(SDL_DROPFILE, SDL_ENABLE)
         SDL_EventState(SDL_DROPTEXT, SDL_ENABLE)
@@ -437,7 +437,7 @@ cdef class _WindowSDL2Storage:
     def set_shape(self, shape, mode, cutoff, color_key):
         cdef SDL_Surface * sdl_shape
 
-        cpdef SDL_WindowShapeMode sdl_window_mode
+        cdef SDL_WindowShapeMode sdl_window_mode
         cdef SDL_WindowShapeParams parameters
         cdef SDL_Color color
         cdef int result
@@ -793,7 +793,7 @@ cdef class _WindowSDL2Storage:
 
     def set_custom_titlebar(self, titlebar_widget):
         SDL_SetWindowBordered(self.win, SDL_FALSE)
-        return SDL_SetWindowHitTest(self.win,custom_titlebar_handler_callback,<void *>titlebar_widget)
+        return SDL_SetWindowHitTest(self.win,<SDL_HitTest>custom_titlebar_handler_callback,<void *>titlebar_widget)
 
     @property
     def window_size(self):
