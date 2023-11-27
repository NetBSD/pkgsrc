$NetBSD: patch-src_main.c,v 1.2 2023/11/27 03:21:00 thorpej Exp $

Allow the default location of the X16 ROM to be overridden.

--- src/main.c.orig	2023-11-06 03:36:56
+++ src/main.c	2023-11-27 02:44:32
@@ -513,9 +513,13 @@ main(int argc, char **argv)
 
 	char *base_path = SDL_GetBasePath();
 
-	// This causes the emulator to load ROM data from the executable's directory when
-	// no ROM file is specified on the command line.
+	// This causes the emulator to load ROM data from the executable's
+	// directory (or somewhere nearby if ROM_RELATIVE_PATH is specified)
+	// when no ROM file is specified on the command line.
 	memcpy(rom_path, base_path, strlen(base_path) + 1);
+#ifdef ROM_RELATIVE_PATH
+	strncpy(rom_path + strlen(rom_path), ROM_RELATIVE_PATH, PATH_MAX - strlen(rom_path));
+#endif
 	strncpy(rom_path + strlen(rom_path), rom_filename, PATH_MAX - strlen(rom_path));
 	memory_randomize_ram(true);
 
