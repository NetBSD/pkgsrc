$NetBSD: patch-bindtextdomain.c,v 1.1 2013/07/26 12:54:39 ryoon Exp $

* Fix build on cygwin, from cygwin's patch.

--- bindtextdomain.c.orig	2012-12-29 22:31:55.000000000 +0000
+++ bindtextdomain.c
@@ -36,12 +36,34 @@ static char *(*r_textdomain)(char const 
 static char *(*r_bindtextdomain)(char const *, char const *) = 0;
 static char *(*r_bind_textdomain_codeset)(char const *, char const *) = 0;
 
+#ifdef __CYGWIN__
+static void *RTLD_NEXT = 0;
+static char *(*r_gettext)(const char *) = 0;
+static char *(*r_dgettext)(const char *, const char *) = 0;
+static char *(*r_dcgettext)(const char *, const char *, int) = 0;
+static char *(*r_ngettext)(const char *, const char *, unsigned long int) = 0;
+static char *(*r_dngettext)(const char *, const char *, const char *,
+                            unsigned long int) = 0;
+static char *(*r_dcngettext)(const char *, const char *, const char *,
+                             unsigned long int, int) = 0;
+static char *(*r_setlocale)(int, const char *) = 0;
+
+#define SYM(sym) libintl_ ## sym
+#else
+#define SYM(sym) sym
+#endif
+
 void setup()
 {
     static int done = 0;
     if (done++)
         return;
 
+#ifdef __CYGWIN__
+    if (!(RTLD_NEXT = dlopen("/usr/bin/cygintl-8.dll", RTLD_LAZY)))
+        die("libintl8 not found");
+#endif
+
     if (!(e_textdomain = getenv("TEXTDOMAIN")))
 	die("TEXTDOMAIN not set");
 
@@ -57,9 +79,19 @@ void setup()
     if (!(r_bind_textdomain_codeset = dlsym(RTLD_NEXT,
     					    "bind_textdomain_codeset")))
 	die("can't find symbol \"bind_textdomain_codeset\"");
+
+#ifdef __CYGWIN__
+    r_gettext = dlsym(RTLD_NEXT, "libintl_gettext");
+    r_dgettext = dlsym(RTLD_NEXT, "libintl_dgettext");
+    r_dcgettext = dlsym(RTLD_NEXT, "libintl_dcgettext");
+    r_ngettext = dlsym(RTLD_NEXT, "libintl_ngettext");
+    r_dngettext = dlsym(RTLD_NEXT, "libintl_dngettext");
+    r_dcngettext = dlsym(RTLD_NEXT, "libintl_dcngettext");
+    r_setlocale = dlsym(RTLD_NEXT, "libintl_setlocale");
+#endif
 }
 
-char *textdomain(char const *domainname)
+char *SYM(textdomain)(char const *domainname)
 {
     char *r;
     setup();
@@ -70,7 +102,7 @@ char *textdomain(char const *domainname)
     return r;
 }
 
-char *bindtextdomain(char const *domainname, char const *dirname)
+char *SYM(bindtextdomain)(char const *domainname, char const *dirname)
 {
     char const *dir = dirname;
     setup();
@@ -80,7 +112,7 @@ char *bindtextdomain(char const *domainn
     return r_bindtextdomain(domainname, dir);
 }
 
-char *bind_textdomain_codeset(char const *domainname, char const *codeset)
+char *SYM(bind_textdomain_codeset)(char const *domainname, char const *codeset)
 {
     char *r;
     setup();
@@ -90,3 +122,54 @@ char *bind_textdomain_codeset(char const
 
     return r;
 }
+
+#ifdef __CYGWIN__
+
+char *libintl_gettext(const char *msgid)
+{
+    setup();
+    return r_gettext(msgid);
+}
+
+char *libintl_dgettext (const char *domainname, const char *msgid)
+{
+    setup();
+    return r_dgettext(domainname, msgid);
+}
+
+char *libintl_dcgettext (const char *domainname, const char *msgid,
+                         int category)
+{
+    setup();
+    return r_dcgettext (domainname, msgid, category);
+}
+
+char *libintl_ngettext (const char *msgid1, const char *msgid2,
+                        unsigned long int n)
+{
+    setup();
+    return r_ngettext (msgid1, msgid2, n);
+}
+
+char *libintl_dngettext (const char *domainname, const char *msgid1,
+                         const char *msgid2, unsigned long int n)
+{
+    setup();
+    return r_dngettext (domainname, msgid1, msgid2, n);
+}
+
+char *libintl_dcngettext (const char *domainname,
+                          const char *msgid1, const char *msgid2,
+                          unsigned long int n, int category)
+{
+    setup();
+    return r_dcngettext (domainname, msgid1, msgid2, n, category);
+}
+
+char *libintl_setlocale (int i, const char *s)
+{
+    setup();
+    return r_setlocale (i, s);
+}
+
+#endif
