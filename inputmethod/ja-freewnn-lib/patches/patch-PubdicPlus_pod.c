$NetBSD: patch-PubdicPlus_pod.c,v 1.1 2011/09/13 07:23:16 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- PubdicPlus/pod.c.orig	2005-11-29 17:00:02.000000000 +0000
+++ PubdicPlus/pod.c
@@ -130,7 +130,7 @@ struct dicpack
 
 #if defined (__STDC__) || defined (_AIX) || (defined (__mips) && defined (_SYSTYPE_SVR4)) || defined(_WIN32)
 /* Prototype for C89 (or later) */
-#ifndef POD_WCHAR
+#ifdef POD_WCHAR
 size_t Mbstowcs (Wchar *d, char *ss, int n);
 size_t Wcstombs (char *d, Wchar *s, int n);
 int    Wscmp (register Wchar *s1, register Wchar *s2);
@@ -139,7 +139,7 @@ int    Wslen (Wchar *s);
 int    Watoi (Wchar *s);
 static void Fputws (Wchar *s, FILE *f);
 Wchar  *Fgetws (Wchar *buf, int siz, FILE *f);
-#endif /* !POD_WCHAR */
+#endif /* POD_WCHAR */
 
 static int all_kana (Wchar *s);
 static Wchar *findslash (Wchar *s);
