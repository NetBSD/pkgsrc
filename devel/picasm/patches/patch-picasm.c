$NetBSD: patch-picasm.c,v 1.2 2020/03/18 17:52:39 joerg Exp $

Fix tautological check.
Remove unused variable.

--- picasm.c.orig	2005-06-29 07:05:34.000000000 +0000
+++ picasm.c
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
