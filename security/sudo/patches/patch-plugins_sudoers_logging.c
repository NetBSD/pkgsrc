$NetBSD: patch-plugins_sudoers_logging.c,v 1.1 2016/01/01 17:00:49 spz Exp $

Make sure CODESET is actually defined, for the sake of
old NetBSD versions

--- ./plugins/sudoers/logging.c.orig	2015-10-31 23:35:25.000000000 +0000
+++ ./plugins/sudoers/logging.c
@@ -722,7 +722,7 @@ send_mail(const char *fmt, ...)
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
