$NetBSD: patch-lib_erl__interface_src_misc_ei__printterm.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- lib/erl_interface/src/misc/ei_printterm.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ lib/erl_interface/src/misc/ei_printterm.c
@@ -186,9 +186,9 @@ static int print_term(FILE* fp, ei_x_buf
     case ERL_SMALL_ATOM_UTF8_EXT:
 	if (ei_decode_atom(buf, index, a) < 0)
 	   goto err;
-	doquote = !islower((int)a[0]);
+	doquote = !islower((unsigned char)a[0]);
 	for (p = a; !doquote && *p != '\0'; ++p)
-	    doquote = !(isalnum((int)*p) || *p == '_' || *p == '@');
+	    doquote = !(isalnum((unsigned char)*p) || *p == '_' || *p == '@');
 	if (doquote) {
 	    xputc('\'', fp, x); ++ch_written; 
 	}
