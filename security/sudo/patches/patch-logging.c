$NetBSD: patch-logging.c,v 1.2 2011/06/19 15:54:55 taca Exp $

Make sure CODESET is actually defined, for the sake of
old NetBSD versions

--- logging.c.orig	2011-02-04 22:59:42.000000000 +0000
+++ logging.c
@@ -619,7 +619,7 @@ send_mail(fmt, va_alist)
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
