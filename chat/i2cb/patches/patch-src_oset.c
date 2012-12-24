$NetBSD: patch-src_oset.c,v 1.1 2012/12/24 03:11:25 dholland Exp $

- don't use "restrict" as an identifier, it's a keyword now

--- src/oset.c~	2000-03-15 22:30:16.000000000 +0000
+++ src/oset.c
@@ -12,7 +12,7 @@
 
 int	oset (TARGLIST);
 int	ounset (TARGLIST);
-void	restrict (void);
+void	setrestricted (void);
 static int	setvar (Tcl_Interp *interp, int type, char *address, char *s);
 static int	unsetvar (Tcl_Interp *interp, int type, char *address);
 static int	listvars (char *name);
@@ -310,7 +310,7 @@ varsanity (void)
 }
 
 void
-restrict (void)
+setrestricted (void)
 {
 	gv.restricted = 1;
 }
