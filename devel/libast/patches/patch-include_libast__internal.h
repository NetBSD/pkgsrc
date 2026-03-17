$NetBSD: patch-include_libast__internal.h,v 1.1 2026/03/17 14:59:35 nia Exp $

Fix implicit declaration of rindex(3).

--- include/libast_internal.h.orig	2026-03-17 14:34:16.119255241 +0000
+++ include/libast_internal.h
@@ -55,6 +55,7 @@
 #ifdef HAVE_STDARG_H
 # include <stdarg.h>
 #endif
+#include <strings.h>
 
 /******************************** MSGS GOOP ***********************************/
 extern spif_charptr_t libast_program_name, libast_program_version;
