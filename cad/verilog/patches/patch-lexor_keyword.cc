$NetBSD: patch-lexor_keyword.cc,v 1.1 2014/06/28 21:05:11 dholland Exp $

Remove inline declarations that sometimes cause build failures. (Seen
in pbulk but not outside, with the same gcc versions and everything;
not at all clear why.) static is an adequate substitute here and
should produce the same results with recent compilers anyhow.

Note that this file is gperf output -- if the build decides to run
gperf it will clobber this patch and the results might or might not
compile depending on whatever unknown factors are involved in it
failing in the first place.

--- lexor_keyword.cc~	2013-08-19 19:12:46.000000000 +0000
+++ lexor_keyword.cc
@@ -108,12 +108,7 @@ keyword_hash (register const char *str, 
   return hval + asso_values[(unsigned char)str[len - 1]];
 }
 
-#ifdef __GNUC__
-__inline
-#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
-__attribute__ ((__gnu_inline__))
-#endif
-#endif
+static
 const struct lexor_keyword *
 check_identifier (register const char *str, register unsigned int len)
 {
