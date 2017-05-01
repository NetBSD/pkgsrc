$NetBSD: patch-ext_File-Glob_bsd_glob.c,v 1.1.2.2 2017/05/01 09:48:24 bsiegert Exp $

[perl #131211] fixup File::Glob degenerate matching
https://research.swtch.com/glob
https://perl5.git.perl.org/perl.git/commit/33252c318625f3c6c89b816ee88481940e3e6f95

--- ext/File-Glob/bsd_glob.c.orig	2017-04-28 18:41:33.000000000 +0000
+++ ext/File-Glob/bsd_glob.c
@@ -911,33 +911,43 @@ globextend(const Char *path, glob_t *pgl
 /*
  * pattern matching function for filenames.  Each occurrence of the *
  * pattern causes a recursion level.
+ *
+ * Note, this function differs from the original as per the discussion
+ * here: https://research.swtch.com/glob
+ *
+ * Basically we removed the recursion and made it use the algorithm
+ * from Russ Cox to not go quadratic on cases like a file called ("a" x 100) . "x"
+ * matched against a pattern like "a*a*a*a*a*a*a*y".
+ *
  */
 static int
 match(Char *name, Char *pat, Char *patend, int nocase)
 {
 	int ok, negate_range;
 	Char c, k;
+	Char *nextp = NULL;
+	Char *nextn = NULL;
 
+    loop:
 	while (pat < patend) {
 		c = *pat++;
 		switch (c & M_MASK) {
 		case M_ALL:
 			if (pat == patend)
 				return(1);
-			do
-			    if (match(name, pat, patend, nocase))
-				    return(1);
-			while (*name++ != BG_EOS)
-				;
-			return(0);
+	                if (*name == BG_EOS)
+	                        return 0;
+			nextn = name + 1;
+	                nextp = pat - 1;
+			break;
 		case M_ONE:
 			if (*name++ == BG_EOS)
-				return(0);
+				goto fail;
 			break;
 		case M_SET:
 			ok = 0;
 			if ((k = *name++) == BG_EOS)
-				return(0);
+				goto fail;
 			if ((negate_range = ((*pat & M_MASK) == M_NOT)) != BG_EOS)
 				++pat;
 			while (((c = *pat++) & M_MASK) != M_END)
@@ -953,16 +963,25 @@ match(Char *name, Char *pat, Char *paten
 				} else if (nocase ? (tolower(c) == tolower(k)) : (c == k))
 					ok = 1;
 			if (ok == negate_range)
-				return(0);
+				goto fail;
 			break;
 		default:
 			k = *name++;
 			if (nocase ? (tolower(k) != tolower(c)) : (k != c))
-				return(0);
+				goto fail;
 			break;
 		}
 	}
-	return(*name == BG_EOS);
+	if (*name == BG_EOS)
+		return 1;
+
+    fail:
+	if (nextn) {
+		pat = nextp;
+		name = nextn;
+		goto loop;
+	}
+	return 0;
 }
 
 /* Free allocated data belonging to a glob_t structure. */
