$NetBSD: patch-erts_emulator_nifs_common_prim__tty__nif.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/nifs/common/prim_tty_nif.c.orig	2024-03-06 15:30:18.000000000 +0000
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
