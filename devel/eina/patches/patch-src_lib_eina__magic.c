$NetBSD: patch-src_lib_eina__magic.c,v 1.1 2011/12/05 17:14:52 joerg Exp $

--- src/lib/eina_magic.c.orig	2011-06-22 16:11:17.000000000 +0000
+++ src/lib/eina_magic.c
@@ -79,7 +79,7 @@ _eina_magic_strings_sort_cmp(const void 
 static int
 _eina_magic_strings_find_cmp(const void *p1, const void *p2)
 {
-   Eina_Magic a = (Eina_Magic)p1;
+   Eina_Magic a = (Eina_Magic)(size_t)p1;
    const Eina_Magic_String *b = p2;
    return a - b->magic;
 }
@@ -206,7 +206,7 @@ eina_magic_string_get(Eina_Magic magic)
         _eina_magic_strings_dirty = 0;
      }
 
-   ems = bsearch((void *)magic, _eina_magic_strings,
+   ems = bsearch((void *)(size_t)magic, _eina_magic_strings,
                  _eina_magic_strings_count, sizeof(Eina_Magic_String),
                  _eina_magic_strings_find_cmp);
    if (ems)
