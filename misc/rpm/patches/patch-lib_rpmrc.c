$NetBSD: patch-lib_rpmrc.c,v 1.2 2017/04/23 08:18:15 adam Exp $

For macros use a path with _arch.
Preprocessor portability fix.

--- lib/rpmrc.c.orig	2017-02-16 09:40:09.000000000 +0000
+++ lib/rpmrc.c
@@ -466,7 +466,7 @@ static void setDefaults(void)
     if (!macrofiles) {
 	macrofiles = rstrscat(NULL, confdir, "/macros", ":",
 				confdir, "/macros.d/macros.*", ":",
-				confdir, "/platform/%{_target}/macros", ":",
+				confdir, "/platform/%{_arch}/macros", ":",
 				confdir, "/fileattrs/*.attr", ":",
   				confdir, "/" RPMCANONVENDOR "/macros", ":",
 				SYSCONFDIR "/rpm/macros.*", ":",
@@ -1028,7 +1028,7 @@ static void defaultMachine(rpmrcCtx ctx,
 	else if(rstreq(un.sysname, "Darwin")) { 
 #ifdef __ppc__
 	    strcpy(un.machine, "ppc");
-#else ifdef __i386__
+#elif defined(__i386__)
 	    strcpy(un.machine, "i386");
 #endif 
 	}
