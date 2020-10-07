$NetBSD: patch-sntp_libopts_autoopts.h,v 1.2 2020/10/07 09:09:39 sjmulder Exp $

* Changes from NetBSD base.
* Compat for noreturn on old compilers

--- sntp/libopts/autoopts.h.orig	2015-04-26 18:43:14.000000000 +0000
+++ sntp/libopts/autoopts.h
@@ -32,7 +32,16 @@
 
 #ifndef AUTOGEN_AUTOOPTS_H
 #define AUTOGEN_AUTOOPTS_H
-#include <stdnoreturn.h>
+
+#if __STDC_VERSION__-0 >= 201112L
+#  include <stdnoreturn.h>
+#elif defined(__GNUC__)
+#  define noreturn __attribute__((noreturn))
+#elif defined(__NetBSD__)
+#  define noreturn __dead
+#else
+#  define noreturn
+#endif
 
 #define AO_NAME_LIMIT           127
 #define AO_NAME_SIZE            ((size_t)(AO_NAME_LIMIT + 1))
@@ -452,7 +461,7 @@ typedef enum { AOFLAG_TABLE } ao_flags_t
 #undef  _aof_
 
 static char const   zNil[] = "";
-static arg_types_t  argTypes             = { NULL };
+static arg_types_t  argTypes             = { .pzStr = NULL };
 static char         line_fmt_buf[32];
 static bool         displayEnum          = false;
 static char const   pkgdatadir_default[] = PKGDATADIR;
