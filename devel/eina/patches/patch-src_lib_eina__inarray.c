$NetBSD: patch-src_lib_eina__inarray.c,v 1.1 2025/12/19 10:27:03 nia Exp $

Include the standard eina boilerplate before using alloca in this file.

Fixes build on systems that require <alloca.h>.

--- src/lib/eina_inarray.c.orig	2025-12-19 10:19:29.729284163 +0000
+++ src/lib/eina_inarray.c
@@ -20,6 +20,19 @@
 # include "config.h"
 #endif
 
+#ifdef HAVE_ALLOCA_H
+# include <alloca.h>
+#elif defined __GNUC__
+# define alloca __builtin_alloca
+#elif defined _AIX
+# define alloca __alloca
+#elif defined _MSC_VER
+# include <malloc.h>
+# define alloca _alloca
+#else
+# include <stdlib.h>
+#endif
+
 #include <stdlib.h>
 #include <string.h>
 
