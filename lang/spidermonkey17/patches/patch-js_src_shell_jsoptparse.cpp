$NetBSD: patch-js_src_shell_jsoptparse.cpp,v 1.1.2.2 2017/06/03 18:33:37 bsiegert Exp $

Pointer fix.

--- js/src/shell/jsoptparse.cpp.orig	2013-02-11 22:33:23.000000000 +0000
+++ js/src/shell/jsoptparse.cpp
@@ -243,7 +243,7 @@ OptionParser::extractValue(size_t argc,
     char *eq = strchr(argv[*i], '=');
     if (eq) {
         *value = eq + 1;
-        if (value[0] == '\0')
+        if (*value[0] == '\0')
             return error("A value is required for option %.*s", eq - argv[*i], argv[*i]);
         return Okay;
     }
