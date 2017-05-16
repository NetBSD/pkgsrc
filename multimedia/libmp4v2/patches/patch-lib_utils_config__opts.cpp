$NetBSD: patch-lib_utils_config__opts.cpp,v 1.1 2017/05/16 09:25:10 jperkin Exp $

Handle SunOS getopt.

--- lib/utils/config_opts.cpp.orig	2004-05-05 23:36:25.000000000 +0000
+++ lib/utils/config_opts.cpp
@@ -22,7 +22,11 @@ struct option *create_long_opts_from_con
   memset(long_options, 0, opts_size);
   
   for (ix = 0; ix < max_vars; ix++) {
+#ifdef __sun
+    long_options[ix].name = (char *)pConfig->GetNameFromIndex(ix);
+#else
     long_options[ix].name = pConfig->GetNameFromIndex(ix);
+#endif
     long_options[ix].has_arg = pConfig->GetTypeFromIndex(ix) == CONFIG_TYPE_BOOL ? 2 : 1;
     long_options[ix].val = base_offset + ix;
   }
