$NetBSD: patch-squint_var.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Avoid naming conflict with standard C.

--- squint/var.c~	2000-02-11 17:04:38.000000000 +0000
+++ squint/var.c
@@ -567,7 +567,7 @@ idel(Proc *proc)
  */
 
 int
-isprint(Proc *proc)
+isprint_(Proc *proc)
 {
 	Store *s;
 	s=emalloc(SHSZ+proc->nprbuf+1);
