$NetBSD: patch-src_main.c,v 1.1 2022/08/07 17:38:08 thorpej Exp $

Allow the default location of the X16 ROM to be overridden.

--- src/main.c.orig	2022-08-07 02:13:20.524132103 +0000
+++ src/main.c	2022-08-07 02:17:36.561192332 +0000
@@ -491,9 +491,13 @@ main(int argc, char **argv)
 
 	char *base_path = SDL_GetBasePath();
 
-	// This causes the emulator to load ROM data from the executable's directory when
-	// no ROM file is specified on the command line.
+	// This causes the emulator to load ROM data from the executable's
+	// directory ((or somewhere nearby if ROM_RELATIVE_PATH is specified)
+	// when no ROM file is specified on the command line.
 	memcpy(rom_path, base_path, strlen(base_path) + 1);
+#ifdef ROM_RELATIVE_PATH
+	strncpy(rom_path + strlen(rom_path), ROM_RELATIVE_PATH, PATH_MAX - strlen(rom_path));
+#endif
 	strncpy(rom_path + strlen(rom_path), rom_filename, PATH_MAX - strlen(rom_path));
 
 	argc--;
