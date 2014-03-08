$NetBSD: patch-logging.c,v 1.3.20.1 2014/03/08 20:33:47 spz Exp $

Make sure CODESET is actually defined, for the sake of
old NetBSD versions

--- logging.c.orig	2013-03-01 11:08:30.000000000 -0500
+++ logging.c	2014-03-08 06:35:19.000000000 -0500
@@ -691,7 +691,7 @@
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
