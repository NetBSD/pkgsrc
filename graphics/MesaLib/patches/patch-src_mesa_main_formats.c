$NetBSD: patch-src_mesa_main_formats.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

--- src/mesa/main/formats.c.orig	2021-07-14 20:04:58.323035200 +0000
+++ src/mesa/main/formats.c
@@ -451,7 +451,11 @@ _mesa_format_to_array_format(mesa_format
 static struct hash_table *format_array_format_table;
 static once_flag format_array_format_table_exists = ONCE_FLAG_INIT;
 
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 format_array_format_table_destroy(void)
 {
    _mesa_hash_table_destroy(format_array_format_table, NULL);
@@ -496,7 +500,9 @@ format_array_format_table_init(void)
                                          (void *)(intptr_t)f);
    }
 
+#if !defined(HAVE_NOATEXIT)
    atexit(format_array_format_table_destroy);
+#endif
 }
 
 mesa_format
