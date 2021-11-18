$NetBSD: patch-sh.func.c,v 1.3 2021/11/18 10:20:47 kim Exp $

Don't glob the filetest builtin arguments twice:    
    https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=905649

https://github.com/tcsh-org/tcsh/commit/8a83d4c717ad4a56450751986b65ccd6ea9eed8a.patch

--- sh.func.c
+++ sh.func.c
@@ -227,7 +227,7 @@ dofiletest(Char **v, struct command *c)
     cleanup_push(globbed, blk_cleanup);
 
     while (*(fileptr = v++) != NULL) {
-	res = filetest(ftest, &fileptr, 0);
+	res = filetest(ftest, &fileptr, TEXP_NOGLOB);
 	cleanup_push(res, xfree);
 	xprintf("%S", res);
 	cleanup_until(res);
