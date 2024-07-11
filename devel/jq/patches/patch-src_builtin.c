$NetBSD: patch-src_builtin.c,v 1.1 2024/07/11 19:59:08 riastradh Exp $

Fix ctype(3) abuse.
https://github.com/jqlang/jq/issues/3151
https://github.com/jqlang/jq/pull/3152

--- src/builtin.c.orig	2023-12-13 19:24:02.000000000 +0000
+++ src/builtin.c
@@ -1440,7 +1440,7 @@ static jv f_strptime(jq_state *jq, jv a,
   }
 #endif
   const char *end = strptime(input, fmt, &tm);
-  if (end == NULL || (*end != '\0' && !isspace(*end))) {
+  if (end == NULL || (*end != '\0' && !isspace((unsigned char)*end))) {
     return ret_error2(a, b, jv_string_fmt("date \"%s\" does not match format \"%s\"", input, fmt));
   }
   jv_free(b);
