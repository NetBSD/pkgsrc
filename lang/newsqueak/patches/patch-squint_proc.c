$NetBSD: patch-squint_proc.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- squint/proc.c~	2000-02-11 17:04:40.000000000 +0000
+++ squint/proc.c
@@ -468,12 +468,12 @@ stacktrace(Proc *p)
 }
 
 int
-Aconv(va_list *va, Fconv *f)
+Aconv(struct va_wrap *va, Fconv *f)
 {
 	int i, n;
 	Store *s;
 	char buf[32];
-	s = va_arg(*va, Store*);
+	s = va_arg(va->ap, Store*);
 	n=s->len;
 	if(n>4)
 		n=4;
@@ -490,11 +490,11 @@ Aconv(va_list *va, Fconv *f)
 }
 
 int
-Cconv(va_list *va, Fconv *f)
+Cconv(struct va_wrap *va, Fconv *f)
 {
 	Store *s;
 
-	s = va_arg(*va, Store*);
+	s = va_arg(va->ap, Store*);
 	if(s->len>128){
 		strconv("\"very long string\"", f);
 		return sizeof(long);
@@ -506,7 +506,7 @@ Cconv(va_list *va, Fconv *f)
 }
 
 int
-Uconv(va_list *va, Fconv *f)
+Uconv(struct va_wrap *va, Fconv *f)
 {
 	USED(va);
 	strconv("unit", f);
