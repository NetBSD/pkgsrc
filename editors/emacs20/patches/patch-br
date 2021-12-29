$NetBSD: patch-br,v 1.2 2021/12/29 03:26:32 dholland Exp $

- Fix extra declarations of allocator functions that are out of sync
with the rest of the tree.

- Disable -fno-common on NetBSD (XXX why? The patch's original commit
message from 2002 says
    -fno-common is not necessary on NetBSD/alpha (or any ELF platform,
     really)
but I don't see why that's true given the associated comment, which
seems valid. (Or at least it is for alpha and mips, where non-library
code is built as PIC.)

--- src/m/alpha.h.orig	2000-02-04 12:25:47.000000000 +0000
+++ src/m/alpha.h
@@ -147,7 +147,9 @@ NOTE-END
    GNU libc, __malloc_initialized would normally be resolved to the
    shared library's .bss section, which is fatal.  */
 # ifdef __GNUC__
-#  define C_SWITCH_MACHINE	-fno-common
+#  ifndef __NetBSD__
+#   define C_SWITCH_MACHINE	-fno-common
+#  endif
 # else
 #  error What gives?  Fix me if DEC Unix supports ELF now.
 # endif
@@ -279,8 +281,9 @@ extern long *xmalloc (), *xrealloc ();
 /* "char *" because ralloc.c defines it that way.  gmalloc.c thinks it
    is allowed to prototype these as "void *" so we don't prototype in
    that case.  You're right: it stinks!  */
-extern char *r_alloc (), *r_re_alloc ();
-extern void r_alloc_free ();
+extern void *r_alloc(void *, unsigned long);
+extern void *r_re_alloc(void *, unsigned long);
+extern void r_alloc_free(void *);
 #endif /* not _MALLOC_INTERNAL */
 #endif /* REL_ALLOC */
 
