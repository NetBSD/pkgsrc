$NetBSD: patch-runtime_sak.c,v 1.1 2022/05/24 18:25:38 jaapb Exp $

Explicit cast to int to eliminate warning

--- runtime/sak.c.orig	2022-02-21 15:57:25.000000000 +0000
+++ runtime/sak.c
@@ -123,7 +123,7 @@ void add_stdlib_prefix(int count, char_o
     } else {
       /* name is a null-terminated string, so an empty string simply has the
          null-terminator "capitalised". */
-      *name = toupper_os(*name);
+      *name = toupper_os((int) *name);
       printf_os(T(" stdlib__%s"), name);
     }
   }
