$NetBSD: patch-match.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- match.c.orig	2026-05-16 21:27:46.850200444 +0000
+++ match.c
@@ -5,7 +5,7 @@
  *	String/Subject matching routines.
  */
 
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "regexp.h"
@@ -37,11 +37,11 @@ fold_string(register char *mask)
     for (; (c = *mask); mask++) {
 
 #ifdef _tolower
-	if (!isascii(c) || !isupper(c))
+	if (!ISASCII(c) || !ISUPPER(c))
 	    continue;
-	*mask = _tolower(c);
+	*mask = _TOLOWER(c);
 #else
-	*mask = tolower(c);
+	*mask = TOLOWER(c);
 #endif
     }
 }
@@ -58,10 +58,10 @@ streq_fold(register char *mask, register
 	    continue;
 
 #ifdef _tolower
-	if (!isascii(c) || !isupper(c) || _tolower(c) != (unsigned) d)
+	if (!ISASCII(c) || !ISUPPER(c) || _TOLOWER(c) != (unsigned) d)
 	    return 0;
 #else
-	if (tolower(c) != d)
+	if (TOLOWER(c) != d)
 	    return 0;
 #endif
     }
@@ -79,12 +79,12 @@ strmatch_fold(char *mask, register char 
 		break;
 
 #ifdef _tolower
-	    if (!isascii(c) || !isupper(c))
+	    if (!ISASCII(c) || !ISUPPER(c))
 		continue;
-	    if (_tolower(c) == (unsigned) m1)
+	    if (_TOLOWER(c) == (unsigned) m1)
 		break;
 #else
-	    if (tolower(c) == m1)
+	    if (TOLOWER(c) == m1)
 		break;
 #endif
 	}
@@ -139,9 +139,9 @@ regexec_fold(register regexp * prog, cha
     while (bp < maxb && (c = *str++) != NUL)
 
 #ifdef _tolower
-	*bp++ = (!isascii(c) || !isupper(c)) ? c : _tolower(c);
+	*bp++ = (!ISASCII(c) || !ISUPPER(c)) ? c : _TOLOWER(c);
 #else
-	*bp++ = tolower(c);
+	*bp++ = TOLOWER(c);
 #endif
 
     *bp = NUL;
