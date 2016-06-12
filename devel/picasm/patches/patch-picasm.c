$NetBSD: patch-picasm.c,v 1.1 2016/06/12 20:03:45 kamil Exp $

Remove unused variable.

--- picasm.c.orig	2005-06-29 07:05:34.000000000 +0000
+++ picasm.c
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
