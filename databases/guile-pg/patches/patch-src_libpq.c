$NetBSD: patch-src_libpq.c,v 1.1 2013/03/13 23:30:42 gdt Exp $

Patch from upstream author to address segfault when a member of
PQconndefaults() does not have an envvar.  Expected in next upstream
release.

--- src/libpq.c.orig	2012-04-29 11:50:08.000000000 +0000
+++ src/libpq.c
@@ -1174,11 +1174,11 @@ presenting this option in the first plac
   for (head = opt = PQconndefaults (); opt && opt->keyword; opt++)
     rv = CONS
       (PCHAIN (scm_c_make_keyword (opt->keyword),
-               PAIRX (envvar,   STRING (opt->envvar)),
+               PAIRM (envvar,   STRING (opt->envvar)),
                PAIRM (compiled, STRING (opt->compiled)),
                PAIRM (val,      STRING (opt->val)),
                PAIRM (label,    STRING (opt->label)),
                PAIRM (dispchar, CHARACTER (opt->dispchar[0])),
                PAIRX (dispsize, NUM_INT (opt->dispsize))),
        rv);
 
