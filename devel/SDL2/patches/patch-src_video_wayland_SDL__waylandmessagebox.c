$NetBSD: patch-src_video_wayland_SDL__waylandmessagebox.c,v 1.1 2021/08/11 20:12:25 nia Exp $

Avoid conflict if stdout is a macro.

--- src/video/wayland/SDL_waylandmessagebox.c.orig	2021-07-27 14:52:29.000000000 +0000
+++ src/video/wayland/SDL_waylandmessagebox.c
@@ -116,7 +116,7 @@ Wayland_ShowMessageBox(const SDL_Message
                     size_t output_len = 1;
                     char* output = NULL;
                     char* tmp = NULL;
-                    FILE* stdout = NULL;
+                    FILE* stdout_ = NULL;
 
                     close(fd_pipe[1]); /* no writing to pipe */
                     /* At this point, if no button ID is needed, we can just bail as soon as the
@@ -144,14 +144,14 @@ Wayland_ShowMessageBox(const SDL_Message
                     }
                     output[0] = '\0';
 
-                    stdout = fdopen(fd_pipe[0], "r");
-                    if (!stdout) {
+                    stdout_ = fdopen(fd_pipe[0], "r");
+                    if (!stdout_) {
                         SDL_free(output);
                         close(fd_pipe[0]);
                         return SDL_SetError("Couldn't open pipe for reading: %s", strerror(errno));
                     }
-                    tmp = fgets(output, output_len + 1, stdout);
-                    fclose(stdout);
+                    tmp = fgets(output, output_len + 1, stdout_);
+                    fclose(stdout_);
 
                     if ((tmp == NULL) || (*tmp == '\0') || (*tmp == '\n')) {
                         SDL_free(output);
