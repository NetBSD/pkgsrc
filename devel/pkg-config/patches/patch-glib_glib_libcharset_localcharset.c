$NetBSD: patch-glib_glib_libcharset_localcharset.c,v 1.1 2013/04/13 11:10:05 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/libcharset/localcharset.c.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/libcharset/localcharset.c
@@ -46,10 +46,6 @@
 #   include <locale.h>
 #  endif
 # endif
-# ifdef __CYGWIN__
-#  define WIN32_LEAN_AND_MEAN
-#  include <windows.h>
-# endif
 #elif defined WIN32_NATIVE
 # define WIN32_LEAN_AND_MEAN
 # include <windows.h>
@@ -111,7 +107,7 @@ _g_locale_get_charset_aliases (void)
   cp = charset_aliases;
   if (cp == NULL)
     {
-#if !(defined VMS || defined WIN32_NATIVE || defined __CYGWIN__)
+#if !(defined VMS || defined WIN32_NATIVE)
       FILE *fp;
       const char *dir;
       const char *base = "charset.alias";
@@ -237,7 +233,7 @@ _g_locale_get_charset_aliases (void)
 	   "DECKOREAN" "\0" "EUC-KR" "\0";
 # endif
 
-# if defined WIN32_NATIVE || defined __CYGWIN__
+# if defined WIN32_NATIVE
       /* To avoid the troubles of installing a separate file in the same
 	 directory as the DLL and of retrieving the DLL's directory at
 	 runtime, simply inline the aliases here.  */
@@ -292,53 +288,6 @@ _g_locale_charset_raw (void)
   /* Most systems support nl_langinfo (CODESET) nowadays.  */
   codeset = nl_langinfo (CODESET);
 
-#  ifdef __CYGWIN__
-  /* Cygwin 2006 does not have locales.  nl_langinfo (CODESET) always
-     returns "US-ASCII".  As long as this is not fixed, return the suffix
-     of the locale name from the environment variables (if present) or
-     the codepage as a number.  */
-  if (codeset != NULL && strcmp (codeset, "US-ASCII") == 0)
-    {
-      const char *locale;
-      static char buf[2 + 10 + 1];
-
-      locale = getenv ("LC_ALL");
-      if (locale == NULL || locale[0] == '\0')
-	{
-	  locale = getenv ("LC_CTYPE");
-	  if (locale == NULL || locale[0] == '\0')
-	    locale = getenv ("LANG");
-	}
-      if (locale != NULL && locale[0] != '\0')
-	{
-	  /* If the locale name contains an encoding after the dot, return
-	     it.  */
-	  const char *dot = strchr (locale, '.');
-
-	  if (dot != NULL)
-	    {
-	      const char *modifier;
-
-	      dot++;
-	      /* Look for the possible @... trailer and remove it, if any.  */
-	      modifier = strchr (dot, '@');
-	      if (modifier == NULL)
-		return dot;
-	      if (modifier - dot < sizeof (buf))
-		{
-		  memcpy (buf, dot, modifier - dot);
-		  buf [modifier - dot] = '\0';
-		  return buf;
-		}
-	    }
-	}
-
-      /* Woe32 has a function returning the locale's codepage as a number.  */
-      sprintf (buf, "CP%u", GetACP ());
-      codeset = buf;
-    }
-#  endif
-
 # else
 
   /* On old systems which lack it, use setlocale or getenv.  */
