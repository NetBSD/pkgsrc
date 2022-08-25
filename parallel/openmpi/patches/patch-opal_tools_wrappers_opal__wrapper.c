$NetBSD: patch-opal_tools_wrappers_opal__wrapper.c,v 1.1 2022/08/25 22:09:14 thor Exp $

# Add rpath support

--- opal/tools/wrappers/opal_wrapper.c.orig	2022-07-30 14:00:47.068421047 +0000
+++ opal/tools/wrappers/opal_wrapper.c
@@ -57,6 +57,7 @@
 
 #define OPAL_INCLUDE_FLAG  "-I"
 #define OPAL_LIBDIR_FLAG   "-L"
+#define OPAL_RPATH_FLAG    "-R"
 
 struct options_data_t {
     char **compiler_args;
@@ -347,6 +348,8 @@ data_callback(const char *key, const cha
                 char *line;
                 asprintf(&line, OPAL_INCLUDE_FLAG"%s",
                          options_data[parse_options_idx].path_opalincludedir);
+                asprintf(&line, OPAL_RPATH_FLAG"%s",
+                         options_data[parse_options_idx].path_libdir);
                 opal_argv_append_nosize(&options_data[parse_options_idx].preproc_flags, line);
                 free(line);
             }
@@ -358,6 +361,8 @@ data_callback(const char *key, const cha
             char *line;
             asprintf(&line, OPAL_LIBDIR_FLAG"%s",
                      options_data[parse_options_idx].path_opallibdir);
+            asprintf(&line, OPAL_RPATH_FLAG"%s",
+                     options_data[parse_options_idx].path_libdir);
             opal_argv_append_nosize(&options_data[parse_options_idx].link_flags, line);
             free(line);
         }
