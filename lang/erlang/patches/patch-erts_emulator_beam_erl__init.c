$NetBSD: patch-erts_emulator_beam_erl__init.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/beam/erl_init.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/beam/erl_init.c
@@ -262,7 +262,7 @@ this_rel_num(void)
 	char this_rel_str[] = ERLANG_OTP_RELEASE;
 	    
 	i = 0;
-	while (this_rel_str[i] && !isdigit((int) this_rel_str[i]))
+	while (this_rel_str[i] && !isdigit((unsigned char) this_rel_str[i]))
 	    i++;
 	this_rel = atoi(&this_rel_str[i]); 
 	if (this_rel < 1)
