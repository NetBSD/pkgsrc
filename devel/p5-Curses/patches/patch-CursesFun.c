$NetBSD: patch-CursesFun.c,v 1.1 2014/09/22 10:47:18 jperkin Exp $

Not all curses implementations have KEY_CODE_YES, use KEY_MIN
there instead. XXX: arguably should be default?

--- CursesFun.c.orig	2014-04-05 17:09:37.000000000 +0000
+++ CursesFun.c
@@ -6968,7 +6968,11 @@ XS(XS_CURSES_getchar) {
 	int key = wgetch(win);
 	if (key == ERR) {
 		XSRETURN_UNDEF;
+#ifdef KEY_CODE_YES
 	} else if (key < KEY_CODE_YES) {
+#else
+	} else if (key < KEY_MIN) {
+#endif
 		ST(0) = sv_newmortal();
 		c_wchar2sv(ST(0), key);
 		XSRETURN(1);
