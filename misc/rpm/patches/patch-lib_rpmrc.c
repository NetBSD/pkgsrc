$NetBSD: patch-lib_rpmrc.c,v 1.3 2025/02/07 15:06:19 adam Exp $

For macros use a path with _arch.

--- lib/rpmrc.c.orig	2024-10-07 09:35:46.000000000 +0000
+++ lib/rpmrc.c
@@ -493,7 +493,7 @@ static void setDefaults(void)
     if (!macrofiles) {
 	macrofiles = rstrscat(NULL, confdir, "/macros", ":",
 				confdir, "/macros.d/macros.*", ":",
-				confdir, "/platform/%{_target}/macros", ":",
+				confdir, "/platform/%{_arch}/macros", ":",
 				confdir, "/fileattrs/*.attr", ":",
 				confdir, "/" RPM_VENDOR "/macros", ":",
 				SYSCONFDIR "/rpm/macros.*", ":",
