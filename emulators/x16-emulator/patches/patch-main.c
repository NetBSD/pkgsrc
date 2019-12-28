$NetBSD: patch-main.c,v 1.1 2019/12/28 19:32:18 thorpej Exp $

Allow the default location of the X16 ROM to be overridden.

--- main.c.orig	2019-12-28 19:00:35.000000000 +0000
+++ main.c
@@ -436,9 +436,13 @@ main(int argc, char **argv)
 
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
 
 	argc--;
