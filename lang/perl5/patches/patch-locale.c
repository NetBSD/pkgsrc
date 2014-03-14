$NetBSD: patch-locale.c,v 1.1 2014/03/14 22:41:10 ryoon Exp $

--- locale.c.orig	2014-01-06 22:46:45.000000000 +0000
+++ locale.c
@@ -517,6 +517,13 @@ Perl_init_i18nl10n(pTHX_ int printwarn)
 	 char *codeset = NULL;
 #if defined(HAS_NL_LANGINFO) && defined(CODESET)
 	 codeset = nl_langinfo(CODESET);
+/*
+ * SCO OpenServer 5.0.7/3.2's nl_langinfo(CODESET) always returns empty.
+ */
+#if defined(_SCO_DS)
+	 strncpy(codeset, "646", 3);
+	 codeset[3] = '\0';
+#endif
 #endif
 	 if (codeset)
 	      utf8locale = (foldEQ(codeset, STR_WITH_LEN("UTF-8"))
