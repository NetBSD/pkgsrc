$NetBSD: patch-logging.c,v 1.1 2011/04/23 17:48:33 hauke Exp $

Make sure CODESET is actually defined, for the sake of
old NetBSD versions

--- logging.c.orig	Fri Feb  4 22:59:42 2011
+++ logging.c
@@ -619,7 +619,7 @@ send_mail(fmt, va_alist)
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
