$NetBSD: patch-texk_web2c_luatexdir_lua_luainit.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/luainit.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/luainit.c	2023/05/02 15:26:43	66984
@@ -85,6 +85,8 @@ const_string LUATEX_IHELP[] = {
     "   --lua=FILE                    load and execute a lua initialization script",
     "   --[no-]mktex=FMT              disable/enable mktexFMT generation (FMT=tex/tfm)",
     "   --nosocket                    disable the lua socket library",
+    "   --no-socket                   disable the lua socket library",
+    "   --socket                      enable the lua socket library",
     "   --output-comment=STRING       use STRING for DVI file comment instead of date (no effect for PDF)",
     "   --output-directory=DIR        use existing DIR as the directory to write files in",
     "   --output-format=FORMAT        use FORMAT for job output; FORMAT is 'dvi' or 'pdf'",
@@ -108,6 +110,7 @@ const_string LUATEX_IHELP[] = {
 #endif
     "",
     "See the reference manual for more information about the startup process.",
+    "LuaTeX package page: https://ctan.org/pkg/luatex",
     NULL
 };
 
@@ -212,9 +215,30 @@ char *jithash_hashname = NULL;
 #endif
 
 int safer_option = 0;
-int nosocket_option = 0;
+int nosocket_option = 1; 
+int nosocket_cli_option = 0; 
+int yessocket_cli_option = 0; 
+int socket_bitmask = 0; 
 int utc_option = 0;
 
+/*tex We use a bitmask for the socket library: |0000| and |1xxx| implies |--nosocket|,
+  otherwise the socket library is enabled. Default value is |0000|, i.e. |--nosocket|.
+*/
+#define UPDATE_SOCKET_STATUS() do {                                                              \
+ socket_bitmask = 0;                                                                             \
+ socket_bitmask = safer_option==1?                             (8+socket_bitmask):socket_bitmask;\
+ socket_bitmask = nosocket_cli_option==1?                      (4+socket_bitmask):socket_bitmask;\
+ socket_bitmask = (shellenabledp == 1 && restrictedshell == 0)?(2+socket_bitmask):socket_bitmask;\
+ socket_bitmask = yessocket_cli_option==1?                     (1+socket_bitmask):socket_bitmask;\
+ if( socket_bitmask==0) {                                                                        \
+   nosocket_option = 1;                                                                          \
+ } else if ( socket_bitmask<4) {                                                                 \
+   nosocket_option = 0;                                                                          \
+ } else {                                                                                        \
+   nosocket_option = 1;                                                                          \
+ }                                                                                               \
+} while (0)
+
 /*tex
 
 Test whether getopt found an option ``A''. Assumes the option index is in the
@@ -242,7 +266,9 @@ static struct option long_options[] = {
 #endif
     {"safer", 0, &safer_option, 1},
     {"utc", 0, &utc_option, 1},
-    {"nosocket", 0, &nosocket_option, 1},
+    {"nosocket", 0, &nosocket_cli_option, 1},
+    {"no-socket", 0, &nosocket_cli_option, 1},
+    {"socket", 0, &yessocket_cli_option, 1},
     {"help", 0, 0, 0},
     {"ini", 0, &ini_version, 1},
     {"interaction", 1, 0, 0},
@@ -524,14 +550,11 @@ static void parse_options(int ac, char *
                 input_name = xstrdup(sargv[sargc-1]);
             sargv[sargc-1] = normalize_quotes(input_name, "argument");
         }
-        if (safer_option)      /* --safer implies --nosocket */
-            nosocket_option = 1;
+	UPDATE_SOCKET_STATUS();
         return;
 #endif
     }
-    /*tex |--safer| implies |--nosocket| */
-    if (safer_option)
-        nosocket_option = 1;
+    UPDATE_SOCKET_STATUS();
     /*tex Finalize the input filename. */
     if (input_name != NULL) {
         argv[optind] = normalize_quotes(input_name, "argument");
@@ -981,6 +1004,7 @@ void lua_initialize(int ac, char **av)
         shellenabledp = true;
         restrictedshell = false;
         safer_option = 0;
+	nosocket_option = 0;
     }
     /*tex
         Get the current locale (it should be |C|) and save |LC_CTYPE|, |LC_COLLATE|
@@ -1149,6 +1173,7 @@ void lua_initialize(int ac, char **av)
             }
             free(v1);
         }
+	UPDATE_SOCKET_STATUS();
         /*tex If shell escapes are restricted, get allowed cmds from cnf.  */
         if (shellenabledp && restrictedshell == 1) {
             v1 = NULL;
