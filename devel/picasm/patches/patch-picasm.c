$NetBSD: patch-picasm.c,v 1.3 2021/12/27 04:54:04 dholland Exp $

Fix tautological check.
Remove unused variable.
Use memcpy instead of strncpy for copying an already-computed length.

--- picasm.c.orig	2005-06-29 07:05:34.000000000 +0000
+++ picasm.c
@@ -109,7 +109,7 @@ err_line_ref(void)
 	len = strlen(line_buffer);
 	if(len > 100)
 	    len = 100;
-	strncpy(outbuf, line_buffer, len);
+	memcpy(outbuf, line_buffer, len);
 	outbuf[len] = '\0';
 	err_out(outbuf);
     }
@@ -895,7 +895,7 @@ gen_byte_c(int instr_code)
 	sym = lookup_symbol(token_string, symtype);
 	if(sym != NULL && sym->type != SYM_FORWARD)
 	{
-	    if(sym->type != SYM_SET || sym->type != SYM_DEFINED)
+	    if(sym->type != SYM_SET && sym->type != SYM_DEFINED)
 	    {
 		error(1, "Invalid symbol type");
 		return FAIL;
@@ -1866,7 +1866,7 @@ int
 main(int argc, char *argv[])
 {
     static char in_filename[256], out_filename[256],
-	list_filename[256], sym_filename[256];
+	list_filename[256];
     static int out_format = IHX8M;
     int listing = 0, symdump = 0;
     char *p;
@@ -1877,7 +1877,6 @@ main(int argc, char *argv[])
     pic_instr_set = PIC_NONE;
     out_filename[0] = '\0';
     list_filename[0] = '\0';
-    sym_filename[0] = '\0';
     warnlevel = 0;
 
     init_assembler();
