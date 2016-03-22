$NetBSD: patch-pcre_compile.c,v 1.2 2016/03/22 19:38:15 tez Exp $

Fix for CVE-2016-1283 from
 http://vcs.pcre.org/pcre?view=revision&revision=1636

Fix for CVE-2016-3191 from
 http://vcs.pcre.org/pcre?view=revision&revision=1631

--- pcre_compile.c.orig	2015-11-23 12:37:21.000000000 +0000
+++ pcre_compile.c
@@ -6,7 +6,7 @@
 and semantics are as close as possible to those of the Perl 5 language.
 
                        Written by Philip Hazel
-           Copyright (c) 1997-2014 University of Cambridge
+           Copyright (c) 1997-2016 University of Cambridge
 
 -----------------------------------------------------------------------------
 Redistribution and use in source and binary forms, with or without
@@ -560,6 +560,7 @@ static const char error_texts[] =
   /* 85 */
   "parentheses are too deeply nested (stack check)\0"
   "digits missing in \\x{} or \\o{}\0"
+  "regular expression is too complicated\0"
   ;
 
 /* Table to identify digits and hex digits. This is used when compiling
@@ -4591,7 +4592,8 @@ for (;; ptr++)
     if (code > cd->start_workspace + cd->workspace_size -
         WORK_SIZE_SAFETY_MARGIN)                       /* Check for overrun */
       {
-      *errorcodeptr = ERR52;
+      *errorcodeptr = (code >= cd->start_workspace + cd->workspace_size)?
+       ERR52 : ERR87;
       goto FAILED;
       }
 
@@ -6604,8 +6606,21 @@ for (;; ptr++)
             cd->had_accept = TRUE;
             for (oc = cd->open_caps; oc != NULL; oc = oc->next)
               {
-              *code++ = OP_CLOSE;
-              PUT2INC(code, 0, oc->number);
+              if (lengthptr != NULL)
+                {
+#ifdef COMPILE_PCRE8
+                *lengthptr += 1 + IMM2_SIZE;
+#elif defined COMPILE_PCRE16
+                *lengthptr += 2 + IMM2_SIZE;
+#elif defined COMPILE_PCRE32
+                *lengthptr += 4 + IMM2_SIZE;
+#endif
+                }
+              else
+                {
+                *code++ = OP_CLOSE;
+                PUT2INC(code, 0, oc->number);
+                }
               }
             setverb = *code++ =
               (cd->assert_depth > 0)? OP_ASSERT_ACCEPT : OP_ACCEPT;
@@ -7274,7 +7289,12 @@ for (;; ptr++)
           so far in order to get the number. If the name is not found, leave
           the value of recno as 0 for a forward reference. */
 
-          else
+	  /* This patch (removing "else") fixes a problem when a reference is
+	  to multiple identically named nested groups from within the nest.
+	  Once again, it is not the "proper" fix, and it results in an
+	  over-allocation of memory. */
+
+          /* else */
             {
             ng = cd->named_groups;
             for (i = 0; i < cd->names_found; i++, ng++)
