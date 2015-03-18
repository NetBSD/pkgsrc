$NetBSD: patch-exec.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- exec.cpp.orig	2015-03-17 21:57:15.000000000 +0000
+++ exec.cpp
@@ -572,7 +572,7 @@ static void exec_no_exec(parser_t &parse
         if (builtin_name_cstr != NULL)
         {
             const wcstring builtin_name = builtin_name_cstr;
-            if (contains(builtin_name, L"for", L"function", L"begin", L"switch"))
+            if (contains(&builtin_name, L"for", L"function", L"begin", L"switch"))
             {
                 // The above builtins are the ones that produce an unbalanced block from within their function implementation
                 // This list should be maintained somewhere else
