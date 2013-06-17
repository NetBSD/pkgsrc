$NetBSD: patch-regexec.c,v 1.1 2013/06/17 06:54:13 wiz Exp $

Fix regmatch pointer 32-bit wraparound regression

Cherry-picked from:

commit 285a3ca139d04d2ee1894c9a9110294ee8bb0309
Merge: aad0429 dfb8f19
Author:     Tony Cook <tony@develop-help.com>
AuthorDate: Mon Jun 3 22:28:37 2013 +1000
Commit:     Tony Cook <tony@develop-help.com>
CommitDate: Mon Jun 3 22:28:37 2013 +1000

    [perl #118175] avoid making pointers outside of objects

    In a couple of cases, when strings were allocated above the 2GB line
    on 32-bit CPUs, this could cause regexps to act strangely - not matching
    or crashing perl.

    The final patch in the set prevents pointer creation which the C standard
    describes as undefined behaviour, but is typically safe (as long as the
    pointer isn't derefed)

This regression was introduced into 5.18.0 by commit
4063ade8503ac8877a02fc4eae8ebbe242b9110b.

--- regexec.c.orig	2013-05-05 19:32:18.000000000 +0000
+++ regexec.c
@@ -6662,7 +6662,7 @@ S_regrepeat(pTHX_ regexp *prog, char **s
     scan = *startposp;
     if (max == REG_INFTY)
 	max = I32_MAX;
-    else if (! utf8_target && scan + max < loceol)
+    else if (! utf8_target && loceol - scan > max)
 	loceol = scan + max;
 
     /* Here, for the case of a non-UTF-8 target we have adjusted <loceol> down
@@ -6711,7 +6711,7 @@ S_regrepeat(pTHX_ regexp *prog, char **s
 	    scan = loceol;
 	break;
     case CANY:  /* Move <scan> forward <max> bytes, unless goes off end */
-        if (utf8_target && scan + max < loceol) {
+        if (utf8_target && loceol - scan > max) {
 
             /* <loceol> hadn't been adjusted in the UTF-8 case */
             scan +=  max;
@@ -6730,7 +6730,7 @@ S_regrepeat(pTHX_ regexp *prog, char **s
          * can use UTF8_IS_INVARIANT() even if the pattern isn't UTF-8, as it's
          * true iff it doesn't matter if the argument is in UTF-8 or not */
         if (UTF8_IS_INVARIANT(c) || (! utf8_target && ! is_utf8_pat)) {
-            if (utf8_target && scan + max < loceol) {
+            if (utf8_target && loceol - scan > max) {
                 /* We didn't adjust <loceol> because is UTF-8, but ok to do so,
                  * since here, to match at all, 1 char == 1 byte */
                 loceol = scan + max;
@@ -6910,7 +6910,7 @@ S_regrepeat(pTHX_ regexp *prog, char **s
         /* FALLTHROUGH */
 
     case POSIXA:
-        if (utf8_target && scan + max < loceol) {
+        if (utf8_target && loceol - scan > max) {
 
             /* We didn't adjust <loceol> at the beginning of this routine
              * because is UTF-8, but it is actually ok to do so, since here, to
