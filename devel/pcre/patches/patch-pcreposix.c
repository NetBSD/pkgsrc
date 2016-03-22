$NetBSD: patch-pcreposix.c,v 1.1 2016/03/22 19:38:15 tez Exp $

Fix for CVE-2016-3191 from
 http://vcs.pcre.org/pcre?view=revision&revision=1631

--- pcreposix.c.orig	2016-03-22 19:29:47.648202900 +0000
+++ pcreposix.c
@@ -6,7 +6,7 @@
 and semantics are as close as possible to those of the Perl 5 language.
 
                        Written by Philip Hazel
-           Copyright (c) 1997-2014 University of Cambridge
+           Copyright (c) 1997-2016 University of Cambridge
 
 -----------------------------------------------------------------------------
 Redistribution and use in source and binary forms, with or without
@@ -173,7 +173,8 @@ static const int eint[] = {
   REG_BADPAT,  /* group name must start with a non-digit */
   /* 85 */
   REG_BADPAT,  /* parentheses too deeply nested (stack check) */
-  REG_BADPAT   /* missing digits in \x{} or \o{} */
+  REG_BADPAT,  /* missing digits in \x{} or \o{} */
+  REG_BADPAT   /* pattern too complicated */
 };
 
 /* Table of texts corresponding to POSIX error codes */
