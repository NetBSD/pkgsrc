$NetBSD: patch-src_cmd_ld_pobj.c,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/cmd/ld/pobj.c.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/cmd/ld/pobj.c
@@ -151,6 +151,12 @@ main(int argc, char *argv[])
 	if(headstring == nil)
 		headstring = headstr(HEADTYPE);
 
+	if (HEADTYPE == Hsolaris && debug['d'] != 0) {
+		fprint(2, "%cl: -d is not supported with this target\n",
+		    thechar);
+		exits("usage");
+	}
+
 	archinit();
 	ctxt->debugfloat = debug['F'];
 
@@ -188,6 +194,7 @@ main(int argc, char *argv[])
 	pclntab();
 	symtab();
 	dodata();
+	dodynsym();
 	address();
 	doweak();
 	reloc();
