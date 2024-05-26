$NetBSD: patch-src_specific_s__filesystem.c,v 1.1 2024/05/26 10:29:06 nia Exp $

Use the current working directory rather than the "bin" directory to
store files.

--- src/specific/s_filesystem.c.orig	2024-05-26 09:15:28.331155609 +0000
+++ src/specific/s_filesystem.c
@@ -52,7 +52,7 @@ static void S_File_PathAppendPart(char *
 const char *S_File_GetGameDirectory(void)
 {
     if (!m_GameDir) {
-        m_GameDir = SDL_GetBasePath();
+        m_GameDir = "./";
         if (!m_GameDir) {
             LOG_ERROR("Can't get module handle");
             return NULL;
