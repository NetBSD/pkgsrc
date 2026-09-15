$NetBSD: patch-src-diclib_xstr.c,v 1.1 2026/09/15 13:00:15 wiz Exp $

Do not dereference a NULL xstr.  reorder_by_suffix passes anthy_xstrcmp the
result of anthy_get_nth_xstr(0), which is NULL whenever the first value of
the matching SUFFIX_HISTORY row is not a string, and anthy then dies with
SIGSEGV inside anthy_set_string -- so every conversion of a word ending in a
suffix takes down whatever loaded the library.  anthy's own record writer can
produce such a row: write_quote_xstr puts nothing between the quotes when the
value it is handed is empty or damaged.

Fedora added this guard in 2013 as anthy-fix-segfault.patch, for ibus-anthy
crashing in anthy_xstrcmp (their bug 973127), and anthy-unicode -- the fork
that is still maintained -- has the same guard in src-diclib/xstr.c.

--- src-diclib/xstr.c.orig
+++ src-diclib/xstr.c
@@ -384,6 +384,10 @@
 anthy_xstrcmp(xstr *x1, xstr *x2)
 {
   int i, m;
+  if (!x1)
+    return -1;
+  if (!x2)
+    return 1;
   if (x1->len < x2->len) {
     m = x1->len;
   }else{
