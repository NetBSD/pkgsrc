$NetBSD: patch-squint_lex.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Use $PREFIX instead of Rob's homedir.
Muck with fmtinstall to avoid doing undefined/illegal things with va_list.

--- squint/lex.c.orig	2000-02-11 17:04:41.000000000 +0000
+++ squint/lex.c
@@ -349,7 +349,7 @@ newfile(char *s, int stdin)
 		char buf[1024];
 		fd=open(s, 0);
 		if(fd<0 && s[0]!='/' && s[0]!='.'){
-			sprint(buf, "/usr/rob/src/squint/include/%s", s);
+			sprint(buf, PREFIX "/share/squint/include/%s", s);
 			fd=open(buf, 0);
 		}
 		if(fd<0)
@@ -381,14 +381,14 @@ printfileline(char *buf, File *f, int l,
 }
 
 int
-zconv(va_list *va, Fconv *f)
+zconv(struct va_wrap *va, Fconv *f)
 {
 	int o;
 	char buf[4096];
 
 	SET(o);
 	if(f->chr == 'Z')
-		o = va_arg(*va, int);
+		o = va_arg(va->ap, int);
 	if(initializing)
 		strcpy(buf, "squint: ");
 	else{
