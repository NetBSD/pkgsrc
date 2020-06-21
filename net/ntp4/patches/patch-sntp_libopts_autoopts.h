$NetBSD: patch-sntp_libopts_autoopts.h,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- sntp/libopts/autoopts.h.orig	2015-04-26 18:43:14.000000000 +0000
+++ sntp/libopts/autoopts.h
@@ -32,7 +32,11 @@
 
 #ifndef AUTOGEN_AUTOOPTS_H
 #define AUTOGEN_AUTOOPTS_H
+#if 0
 #include <stdnoreturn.h>
+#else
+#define noreturn __dead
+#endif
 
 #define AO_NAME_LIMIT           127
 #define AO_NAME_SIZE            ((size_t)(AO_NAME_LIMIT + 1))
@@ -452,7 +456,7 @@ typedef enum { AOFLAG_TABLE } ao_flags_t
 #undef  _aof_
 
 static char const   zNil[] = "";
-static arg_types_t  argTypes             = { NULL };
+static arg_types_t  argTypes             = { .pzStr = NULL };
 static char         line_fmt_buf[32];
 static bool         displayEnum          = false;
 static char const   pkgdatadir_default[] = PKGDATADIR;
