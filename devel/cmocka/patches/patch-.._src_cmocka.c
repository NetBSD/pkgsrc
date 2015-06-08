$NetBSD: patch-.._src_cmocka.c,v 1.1 2015/06/08 13:38:50 joerg Exp $

--- ../src/cmocka.c.orig	2015-06-08 12:54:44.000000000 +0000
+++ ../src/cmocka.c
@@ -960,7 +960,7 @@ static int memory_equal_display_error(co
     }
     if (differences) {
         cm_print_error("%d bytes of %p and %p differ\n", differences,
-                    a, b);
+                    (const void *)a, (const void *)b);
         return 0;
     }
     return 1;
@@ -985,7 +985,7 @@ static int memory_not_equal_display_erro
     }
     if (same == size) {
         cm_print_error("%"PRIdS "bytes of %p and %p the same\n", same,
-                    a, b);
+                    (const void *)a, (const void *)b);
         return 0;
     }
     return 1;
@@ -1646,7 +1646,7 @@ void _test_free(void* const ptr, const c
                                    file, line,
                                    ptr, (unsigned long)block_info->size,
                                    block_info->location.file, block_info->location.line,
-                                   &guard[j]);
+                                   (const void *)&guard[j]);
                     _fail(file, line);
                 }
             }
