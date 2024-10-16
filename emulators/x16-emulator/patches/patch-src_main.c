$NetBSD: patch-src_main.c,v 1.3 2024/10/16 04:25:32 thorpej Exp $

Allow the default location of the X16 ROM to be overridden.

--- src/main.c.orig	2024-10-16 03:58:55.880047197 +0000
+++ src/main.c	2024-10-16 04:01:17.250721407 +0000
@@ -570,9 +570,13 @@ main(int argc, char **argv)
 
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
 
