$NetBSD: patch-logging.c,v 1.3 2011/09/18 14:18:25 ryoon Exp $

Make sure CODESET is actually defined, for the sake of
old NetBSD versions

--- logging.c.orig	2011-08-13 17:32:04 +0000
+++ logging.c
@@ -573,7 +573,7 @@ send_mail(fmt, va_alist)
 	    (void) fputc(*p, mail);
     }
 
-#ifdef HAVE_NL_LANGINFO
+#if defined(HAVE_NL_LANGINFO) && defined(CODESET)
     if (strcmp(def_sudoers_locale, "C") != 0)
 	(void) fprintf(mail, "\nContent-Type: text/plain; charset=\"%s\"\nContent-Transfer-Encoding: 8bit", nl_langinfo(CODESET));
 #endif /* HAVE_NL_LANGINFO */
