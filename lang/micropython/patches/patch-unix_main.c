$NetBSD: patch-unix_main.c,v 1.1 2017/11/30 14:41:30 hauke Exp $

Adjust default package path.

--- unix/main.c.orig	2017-08-23 01:50:11.000000000 +0000
+++ unix/main.c
@@ -450,7 +450,7 @@ MP_NOINLINE int main_(int argc, char **a
         #ifdef MICROPY_PY_SYS_PATH_DEFAULT
         path = MICROPY_PY_SYS_PATH_DEFAULT;
         #else
-        path = "~/.micropython/lib:/usr/lib/micropython";
+        path = "~/.micropython/lib:%PREFIX%/lib/micropython";
         #endif
     }
     size_t path_num = 1; // [0] is for current dir (or base dir of the script)
