$NetBSD: patch-src_include_prelude-plugin.h,v 1.1 2013/04/12 13:45:48 joerg Exp $

--- src/include/prelude-plugin.h.orig	2009-05-12 07:49:42.000000000 +0000
+++ src/include/prelude-plugin.h
@@ -59,11 +59,8 @@ typedef struct {
  * Hack for plugin preloading,
  * without having the end program depend on ltdl.
  */
-#ifdef PRELUDE_APPLICATION_USE_LIBTOOL2
-# define lt_preloaded_symbols lt__PROGRAM__LTX_preloaded_symbols
-#endif
-
-extern const void *lt_preloaded_symbols[];
+#include <ltdl.h>
+#define lt_preloaded_symbols lt__PROGRAM__LTX_preloaded_symbols
 
 #define PRELUDE_PLUGIN_SET_PRELOADED_SYMBOLS()         \
         prelude_plugin_set_preloaded_symbols(lt_preloaded_symbols)
