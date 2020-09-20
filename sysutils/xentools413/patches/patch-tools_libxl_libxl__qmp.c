$NetBSD: patch-tools_libxl_libxl__qmp.c,v 1.1 2020/09/20 14:17:23 prlw1 Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- tools/libxl/libxl_qmp.c.orig	2020-05-14 12:19:32.000000000 +0000
+++ tools/libxl/libxl_qmp.c
@@ -1226,7 +1226,7 @@ static int qmp_error_class_to_libxl_erro
                 se++;
                 continue;
             }
-            if (tolower(*s) != tolower(*se))
+            if (tolower((unsigned char)*s) != tolower((unsigned char)*se))
                 break;
             s++, se++;
         }
