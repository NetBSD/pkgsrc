$NetBSD: patch-squint_xec.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- squint/xec.c~	2000-02-11 17:04:43.000000000 +0000
+++ squint/xec.c
@@ -21,13 +21,13 @@ void	xec(void);
 void	xxec(void);
 
 int
-iconv(va_list *va, Fconv *f)
+iconv(struct va_wrap *va, Fconv *f)
 {
 	int i;
 	char buf[16];
 	void *o;	/* really int (**o)(Proc*) */
 
-	o = va_arg(*va, void*);
+	o = va_arg(va->ap, void*);
 	for(i=0; i<NInst; i++)
 		if((void*)insttab[i].fp==o){
 			strconv(insttab[i].name, f);
