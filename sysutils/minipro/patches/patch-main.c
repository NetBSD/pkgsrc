$NetBSD: patch-main.c,v 1.1 2022/01/22 17:52:53 thorpej Exp $

Use ctype(3) functions safely.

--- main.c.orig	2022-01-22 15:56:02.000000000 +0000
+++ main.c
@@ -922,7 +922,7 @@ int get_config_value(const char *buffer,
     val = num;
     cur += 2;  // Advances the pointer to the first numeric character
     while (cur < eol) {
-      if (isxdigit(*cur++))  // check for hex digit
+      if (isxdigit((unsigned char)*cur++))  // check for hex digit
       {
         *val++ = *(cur - 1);  // put it in the buffer
       }
