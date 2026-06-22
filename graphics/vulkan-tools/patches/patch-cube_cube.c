$NetBSD: patch-cube_cube.c,v 1.2 2026/06/22 08:17:58 kikadf Exp $

Allow building on NetBSD.
Fix ctype usage

--- cube/cube.c.orig	2026-05-04 19:54:00.000000000 +0200
+++ cube/cube.c
@@ -4780,7 +4780,7 @@ static void demo_init(struct demo *demo,
         if ((strcmp(argv[i], "--wsi") == 0) && (i < argc - 1)) {
             size_t argc_len = strlen(argv[i + 1]);
             for (size_t argc_i = 0; argc_i < argc_len; argc_i++) {
-                argv[i + 1][argc_i] = tolower(argv[i + 1][argc_i]);
+                argv[i + 1][argc_i] = tolower((unsigned char)argv[i + 1][argc_i]);
             }
             WSI_PLATFORM selection = wsi_from_string(argv[i + 1]);
             if (selection == WSI_PLATFORM_INVALID) {
@@ -5098,7 +5098,8 @@ void android_main(struct android_app *ap
         }
     }
 }
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || \
+      defined(__NetBSD__)
 int main(int argc, char **argv) {
     struct demo demo;
 
