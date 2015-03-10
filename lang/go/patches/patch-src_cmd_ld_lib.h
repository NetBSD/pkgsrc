$NetBSD: patch-src_cmd_ld_lib.h,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/cmd/ld/lib.h.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/cmd/ld/lib.h
@@ -216,6 +216,7 @@ char*	decodetype_structfieldname(LSym *s
 vlong	decodetype_structfieldoffs(LSym *s, int i);
 LSym*	decodetype_structfieldtype(LSym *s, int i);
 void	dodata(void);
+void	dodynsym(void);
 void	dostkcheck(void);
 void	dostkoff(void);
 void	dosymtype(void);
