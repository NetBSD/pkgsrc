$NetBSD: patch-squint_error.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- squint/error.c~	2000-02-11 17:04:40.000000000 +0000
+++ squint/error.c
@@ -108,11 +108,11 @@ rpanic(char *s, ...)
 }
 
 int
-bconv(va_list *va, Fconv *f)
+bconv(struct va_wrap *va, Fconv *f)
 {
 	int o;
 	extern int printcol;
-	o = va_arg(*va, int);
+	o = va_arg(va->ap, int);
 	while(printcol<o-8)
 		strconv("\t", f);
 	strconv("        "+(8-(o-printcol)), f);
@@ -120,12 +120,12 @@ bconv(va_list *va, Fconv *f)
 }
 
 int
-nconv(va_list *va, Fconv *f)
+nconv(struct va_wrap *va, Fconv *f)
 {
 	Node *n;
 	int t;
 	char buf[32];
-	n = va_arg(*va, Node*);
+	n = va_arg(va->ap, Node*);
 	t = n->t;
 	if(t<0 || sizeof(Ntypename)/sizeof(Ntypename[0])<=t){
 		sprint(buf, "mystery node(%d)", t);
@@ -136,12 +136,12 @@ nconv(va_list *va, Fconv *f)
 }
 
 int
-tconv(va_list *va, Fconv *f)
+tconv(struct va_wrap *va, Fconv *f)
 {
 	int t;
 	char buf[1024];
 	Node *n;
-	n = va_arg(*va, Node*);
+	n = va_arg(va->ap, Node*);
 	t = n->o.t;
 	if(t<0 || sizeof(Ttypename)/sizeof(Ttypename[0])<=t){
 		sprint(buf, "mystery type(%d)", t);
@@ -156,12 +156,12 @@ tconv(va_list *va, Fconv *f)
 }
 
 int
-econv(va_list *va, Fconv *f)
+econv(struct va_wrap *va, Fconv *f)
 {
 	char buf[16], *x;
 	int t;
 	Node *n;
-	n = va_arg(*va, Node*);
+	n = va_arg(va->ap, Node*);
 	t = n->o.i;
 	if(t<128 && strchr("+-*/%|&^~?!><=", t)){
 		sprint(buf, "%c", t);
@@ -232,11 +232,11 @@ econv(va_list *va, Fconv *f)
 }
 
 int
-mconv(va_list *va, Fconv *f)
+mconv(struct va_wrap *va, Fconv *f)
 {
 	char buf[4096];
 	Node *n;
-	n = va_arg(*va, Node*);
+	n = va_arg(va->ap, Node*);
 	switch(n->t){
 	case NID:
 		strcpy(buf, n->o.s->name);
