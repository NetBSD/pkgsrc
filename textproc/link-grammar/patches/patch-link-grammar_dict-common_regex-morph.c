$NetBSD: patch-link-grammar_dict-common_regex-morph.c,v 1.1 2021/02/26 18:02:24 ryoon Exp $

* regex of NetBSD after 2021-02-26 requires REG_GNU flag to process
  GNU extensions.

--- link-grammar/dict-common/regex-morph.c.orig	2020-08-20 23:59:00.000000000 +0000
+++ link-grammar/dict-common/regex-morph.c
@@ -100,7 +100,11 @@ int compile_regexs(Regex_node *rn, Dicti
 #ifndef REG_ENHANCED
 #define REG_ENHANCED 0
 #endif
+#  if defined(REG_GNU)
+			rc = regcomp(re, rn->pattern, REG_NOSUB|REG_EXTENDED|REG_ENHANCED|REG_GNU);
+#  else
 			rc = regcomp(re, rn->pattern, REG_NOSUB|REG_EXTENDED|REG_ENHANCED);
+#  endif
 #endif
 
 			if (rc)
