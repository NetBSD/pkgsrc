$NetBSD: patch-sh.exp.c,v 1.1 2021/11/18 10:20:47 kim Exp $

Don't glob the filetest builtin arguments twice:    
    https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=905649

https://github.com/tcsh-org/tcsh/commit/8a83d4c717ad4a56450751986b65ccd6ea9eed8a.patch

--- sh.exp.c
+++ sh.exp.c
@@ -36,9 +36,6 @@
  * C shell
  */
 
-#define TEXP_IGNORE 1	/* in ignore, it means to ignore value, just parse */
-#define TEXP_NOGLOB 2	/* in ignore, it means not to globone */
-
 #define	ADDOP	1
 #define	MULOP	2
 #define	EQOP	4
@@ -677,7 +674,11 @@ filetest(Char *cp, Char ***vp, int ignore)
     dp = *(*vp)++;
     if (ignore & TEXP_IGNORE)
 	return (Strsave(STRNULL));
-    ep = globone(dp, G_APPEND);
+    if ((ignore & TEXP_NOGLOB) == 0) {
+	ep = globone(dp, G_APPEND);
+    } else {
+	ep = Strsave(dp);
+    }
     cleanup_push(ep, xfree);
     ft = &cp[1];
     do
