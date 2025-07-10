$NetBSD: patch-erts_emulator_nifs_common_prim__tty__nif.c,v 1.2 2025/07/10 14:23:11 jperkin Exp $

Fix ctype(3) misuse.
Remove broken SunOS patch.

--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2024-07-09 11:36:07.000000000 +0000
+++ erts/emulator/nifs/common/prim_tty_nif.c
@@ -266,7 +266,7 @@ static ERL_NIF_TERM isprint_nif(ErlNifEn
     int i;
     if (enif_get_int(env, argv[0], &i)) {
         ASSERT(i > 0 && i < 256);
-        return isprint((char)i) ? atom_true : atom_false;
+        return isprint((unsigned char)i) ? atom_true : atom_false;
     }
     return enif_make_badarg(env);
 }
@@ -746,11 +746,7 @@ static ERL_NIF_TERM tty_tgetstr_nif(ErlN
 static int tputs_buffer_index;
 static unsigned char tputs_buffer[1024];
 
-#if defined(__sun) && defined(__SVR4) /* Solaris */
-static int tty_puts_putc(char c) {
-#else
 static int tty_puts_putc(int c) {
-#endif
     tputs_buffer[tputs_buffer_index++] = (unsigned char)c;
     return 0;
 }
