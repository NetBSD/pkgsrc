$NetBSD: patch-lib9_doprint.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- lib9/doprint.c~	2000-02-11 17:04:14.000000000 +0000
+++ lib9/doprint.c
@@ -32,21 +32,21 @@ struct Fmtalloc {
 #endif
 	int	convcount;
 	char	index[MAXFMT];
-	int	(*conv[MAXCONV])(va_list*, Fconv*);
+	int	(*conv[MAXCONV])(struct va_wrap *, Fconv*);
 };
 static struct Fmtalloc fmtalloc;
 
-static	int	noconv(va_list*, Fconv*);
-static	int	flags(va_list*, Fconv*);
+static	int	noconv(struct va_wrap *, Fconv*);
+static	int	flags(struct va_wrap *, Fconv*);
 
-static	int	cconv(va_list*, Fconv*);
-static	int	rconv(va_list*, Fconv*);
-static	int	sconv(va_list*, Fconv*);
-static	int	percent(va_list*, Fconv*);
-static	int	column(va_list*, Fconv*);
+static	int	cconv(struct va_wrap *, Fconv*);
+static	int	rconv(struct va_wrap *, Fconv*);
+static	int	sconv(struct va_wrap *, Fconv*);
+static	int	percent(struct va_wrap *, Fconv*);
+static	int	column(struct va_wrap *, Fconv*);
 
-extern	int	numbconv(va_list*, Fconv*);
-extern	int	fltconv(va_list*, Fconv*);
+extern	int	numbconv(struct va_wrap *, Fconv*);
+extern	int	fltconv(struct va_wrap *, Fconv*);
 
 
 static	void
@@ -108,7 +108,7 @@ initfmt(void)
 }
 
 int
-fmtinstall(int c, int (*f)(va_list*, Fconv*))
+fmtinstall(int c, int (*f)(struct va_wrap *, Fconv*))
 {
 
 #ifdef LOCKS_AVAILABLE
@@ -165,6 +165,9 @@ doprint(char *s, char *es, const char *f
 	int n, c;
 	Rune rune;
 	Fconv local;
+	struct va_wrap argwrap;
+
+	va_copy(argwrap.ap, argp);
 
 	if(fmtalloc.convcount <= 0)
 		initfmt();
@@ -252,7 +255,7 @@ l1:
 		goto l1;
 	}
 	if(c == '*') {
-		n = va_arg(argp, int);
+		n = va_arg(argwrap.ap, int);
 		if(local.f1 == NONE)
 			local.f1 = n;
 		else
@@ -263,7 +266,7 @@ l1:
 	if(c >= 0 && c < MAXFMT)
 		n = fmtalloc.index[c];
 	local.chr = c;
-	n = (*fmtalloc.conv[n])(&argp, &local);
+	n = (*fmtalloc.conv[n])(&argwrap, &local);
 	if(n < 0) {
 		local.f3 |= -n;
 		goto l0;
@@ -272,7 +275,7 @@ l1:
 }
 
 int
-numbconv(va_list *arg, Fconv *fp)
+numbconv(struct va_wrap *arg, Fconv *fp)
 {
 	char s[IDIGIT];
 	int i, f, n, b, ucase;
@@ -313,31 +316,31 @@ numbconv(va_list *arg, Fconv *fp)
 	f = 0;
 	switch(fp->f3 & (FVLONG|FLONG|FUNSIGN|FPOINTER)) {
 	case FVLONG|FLONG:
-		vl = va_arg(*arg, vlong);
+		vl = va_arg(arg->ap, vlong);
 		break;
 
 	case FUNSIGN|FVLONG|FLONG:
-		vl = va_arg(*arg, uvlong);
+		vl = va_arg(arg->ap, uvlong);
 		break;
 
 	case FUNSIGN|FPOINTER:
-		v = (ulong)va_arg(*arg, void*);
+		v = (ulong)va_arg(arg->ap, void*);
 		break;
 
 	case FLONG:
-		v = va_arg(*arg, long);
+		v = va_arg(arg->ap, long);
 		break;
 
 	case FUNSIGN|FLONG:
-		v = va_arg(*arg, ulong);
+		v = va_arg(arg->ap, ulong);
 		break;
 
 	default:
-		v = va_arg(*arg, int);
+		v = va_arg(arg->ap, int);
 		break;
 
 	case FUNSIGN:
-		v = va_arg(*arg, unsigned);
+		v = va_arg(arg->ap, unsigned);
 		break;
 	}
 	if(fp->f3 & FVLONG) {
@@ -504,7 +507,7 @@ strconv(char *s, Fconv *fp)
 }
 
 static int
-noconv(va_list *arg, Fconv *fp)
+noconv(struct va_wrap *arg, Fconv *fp)
 {
 	char s[10];
 
@@ -520,7 +523,7 @@ noconv(va_list *arg, Fconv *fp)
 }
 
 static int
-rconv(va_list *arg, Fconv *fp)
+rconv(struct va_wrap *arg, Fconv *fp)
 {
 	char s[ERRLEN];
 
@@ -532,12 +535,12 @@ rconv(va_list *arg, Fconv *fp)
 }
 
 static int
-cconv(va_list *arg, Fconv *fp)
+cconv(struct va_wrap *arg, Fconv *fp)
 {
 	char s[10];
 	Rune rune;
 
-	rune = va_arg(*arg, int);
+	rune = va_arg(arg->ap, int);
 	if(fp->chr == 'c')
 		rune &= 0xff;
 	s[runetochar(s, &rune)] = 0;
@@ -548,18 +551,18 @@ cconv(va_list *arg, Fconv *fp)
 }
 
 static	int
-sconv(va_list *arg, Fconv *fp)
+sconv(struct va_wrap *arg, Fconv *fp)
 {
 	char *s;
 	Rune *r;
 
 	if(fp->chr == 's') {
-		s = va_arg(*arg, char*);
+		s = va_arg(arg->ap, char*);
 		if(s == 0)
 			s = "<null>";
 		strconv(s, fp);
 	} else {
-		r = va_arg(*arg, Rune*);
+		r = va_arg(arg->ap, Rune*);
 		if(r == 0)
 			r = (Rune *)"<n\0u\0l\0l\0>\0\0\0";
 		Strconv(r, fp);
@@ -568,7 +571,7 @@ sconv(va_list *arg, Fconv *fp)
 }
 
 static	int
-percent(va_list *arg, Fconv *fp)
+percent(struct va_wrap *arg, Fconv *fp)
 {
 	pchar('%', fp);
 	printcol++;
@@ -576,11 +579,11 @@ percent(va_list *arg, Fconv *fp)
 }
 
 static	int
-column(va_list *arg, Fconv *fp)
+column(struct va_wrap *arg, Fconv *fp)
 {
 	int col, pc;
 
-	col = va_arg(*arg, int);
+	col = va_arg(arg->ap, int);
 	while(printcol < col) {
 		pc = (printcol+8) & ~7;
 		if(pc <= col) {
@@ -595,7 +598,7 @@ column(va_list *arg, Fconv *fp)
 }
 
 static	int
-flags(va_list *arg, Fconv *fp)
+flags(struct va_wrap *arg, Fconv *fp)
 {
 	int f;
 
@@ -627,7 +630,7 @@ flags(va_list *arg, Fconv *fp)
 }
 
 int
-fltconv(va_list *arg, Fconv *fp)
+fltconv(struct va_wrap *arg, Fconv *fp)
 {
 	char s1[FDIGIT+10], s2[FDIGIT+10];
 	double f, g, h;
@@ -637,7 +640,7 @@ fltconv(va_list *arg, Fconv *fp)
 	f2 = fp->f2;
 	fp->f2 = NONE;
 
-	f = va_arg(*arg, double);
+	f = va_arg(arg->ap, double);
 	if(isNaN(f)){
 		strconv("NaN", fp);
 		return 0;
