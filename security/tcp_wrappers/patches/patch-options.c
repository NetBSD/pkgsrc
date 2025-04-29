$NetBSD: patch-options.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- options.c.orig	1996-02-11 16:01:32.000000000 +0000
+++ options.c
@@ -47,6 +47,8 @@ static char sccsid[] = "@(#) options.c 1
 #include <ctype.h>
 #include <setjmp.h>
 #include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
 
 #ifndef MAXPATHNAMELEN
 #define MAXPATHNAMELEN  BUFSIZ
@@ -66,31 +68,31 @@ extern jmp_buf tcpd_buf;		/* tcpd_jump()
 static char whitespace_eq[] = "= \t\r\n";
 #define whitespace (whitespace_eq + 1)
 
-static char *get_field();		/* chew :-delimited field off string */
-static char *chop_string();		/* strip leading and trailing blanks */
+static char *get_field(char *);		/* chew :-delimited field off string */
+static char *chop_string(char *);		/* strip leading and trailing blanks */
 
 /* List of functions that implement the options. Add yours here. */
 
-static void user_option();		/* execute "user name.group" option */
-static void group_option();		/* execute "group name" option */
-static void umask_option();		/* execute "umask mask" option */
-static void linger_option();		/* execute "linger time" option */
-static void keepalive_option();		/* execute "keepalive" option */
-static void spawn_option();		/* execute "spawn command" option */
-static void twist_option();		/* execute "twist command" option */
-static void rfc931_option();		/* execute "rfc931" option */
-static void setenv_option();		/* execute "setenv name value" */
-static void nice_option();		/* execute "nice" option */
-static void severity_option();		/* execute "severity value" */
-static void allow_option();		/* execute "allow" option */
-static void deny_option();		/* execute "deny" option */
-static void banners_option();		/* execute "banners path" option */
+static void user_option(char *, struct request_info *);		/* execute "user name.group" option */
+static void group_option(char *, struct request_info *);		/* execute "group name" option */
+static void umask_option(char *, struct request_info *);		/* execute "umask mask" option */
+static void linger_option(char *, struct request_info *);		/* execute "linger time" option */
+static void keepalive_option(char *, struct request_info *);		/* execute "keepalive" option */
+static void spawn_option(char *, struct request_info *);		/* execute "spawn command" option */
+static void twist_option(char *, struct request_info *);		/* execute "twist command" option */
+static void rfc931_option(char *, struct request_info *);		/* execute "rfc931" option */
+static void setenv_option(char *, struct request_info *);		/* execute "setenv name value" */
+static void nice_option(char *, struct request_info *);		/* execute "nice" option */
+static void severity_option(char *, struct request_info *);		/* execute "severity value" */
+static void allow_option(char *, struct request_info *);		/* execute "allow" option */
+static void deny_option(char *, struct request_info *);		/* execute "deny" option */
+static void banners_option(char *, struct request_info *);		/* execute "banners path" option */
 
 /* Structure of the options table. */
 
 struct option {
     char   *name;			/* keyword name, case is ignored */
-    void  (*func) ();			/* function that does the real work */
+    void  (*func) (char *, struct request_info *);			/* function that does the real work */
     int     flags;			/* see below... */
 };
 
@@ -250,7 +252,7 @@ char   *value;
 struct request_info *request;
 {
     struct group *grp;
-    struct group *getgrnam();
+    struct group *getgrnam(const char *);
 
     if ((grp = getgrnam(value)) == 0)
 	tcpd_jump("unknown group: \"%s\"", value);
@@ -269,7 +271,7 @@ char   *value;
 struct request_info *request;
 {
     struct passwd *pwd;
-    struct passwd *getpwnam();
+    struct passwd *getpwnam(const char *);
     char   *group;
 
     if ((group = split_at(value, '.')) != 0)
